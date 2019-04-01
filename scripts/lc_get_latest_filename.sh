#!/bin/bash

ls -l | awk '{if(NF==9) print $NF}' | sort -r -n | awk 'NR==1'