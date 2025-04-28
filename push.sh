#!/bin/bash

if [ -z "$1" ]; then
  msg="update on $(date '+%Y-%m-%d %H:%M:%S')"
else
  msg=""$1" $(date '+%Y-%m-%d %H:%M:%S')"
fi

# echo "$msg"
git add .
git commit -m "$msg"
git push && git push github master