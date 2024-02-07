#!/bin/bash

# Work at the root directory
# Should have conanfile.py present there.
cd "$(dirname "$0")"
cd ../..

source scripts/common.sh
_setArgs "$@"

# Call build function from common
build

base_dir="src/targets/experiments/stocks"
executable="build/${BUILD_TYPE}/offline_experiment_stocks"
csv="stock_data.csv"
benchmark_file="$base_dir/benchmark.csv"

queries=$(find "$base_dir/queries" -type f | sort -V) 
TIMEFORMAT=%R

repeats=3

echo "query,time" >$benchmark_file
for query in $queries; do
    echo -e "Running ${query}"
    query_file=$(basename "$query")
    time_taken=$(/usr/bin/time -f "%e" bash -c 'for i in {1..3}; do '"$executable"' '"$base_dir"'/queries/'"$query_file"' '"$base_dir"'/'"$csv"' > '"/dev/null"'; done' 2>&1)
    avg_time=$(echo "$time_taken / $repeats" | bc -l)
    echo "$query_file,$avg_time" >> "$benchmark_file"
done
