#!/bin/bash
long_prefix=`echo ${1%.*}`

echo "$long_prefix" | awk -F '/' '{print $NF}'