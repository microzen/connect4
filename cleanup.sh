#!/bin/bash
find ./ -name 'd.*' -type f -o -name 'o.*' -type f | xargs rm
find ./ -name '*.d' -type f -o -name '*.o' -type f | xargs rm
find ./ -name '*.d.*' -type f -o -name '*.o.*' -type f | xargs rm