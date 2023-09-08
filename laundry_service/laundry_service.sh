#!/bin/bash
g++ laundry_service.cpp -o laundry_service -Wall -std=c++11 -O2 && ./laundry_service
rm -f ./laundry_service
