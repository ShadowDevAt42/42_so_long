#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}Starting map validation tests...${NC}\n"

# Function to test a map and print result
test_map() {
    local map=$1
    echo -e "${BLUE}Testing map: ${map}${NC}"
    ./so_long "$map"
    local result=$?
    
    if [ $result -eq 0 ]; then
        echo -e "${GREEN}✓ Map is valid${NC}"
    else
        echo -e "${RED}✗ Map validation failed${NC}"
    fi
    echo "----------------------------------------"
}

# Test all maps in maps/test directory
for map in maps/test/*.ber maps/test/wrong_ext.txt; do
    test_map "$map"
done

echo -e "\n${BLUE}Map testing completed${NC}"
