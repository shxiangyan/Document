#!/bin/bash

cd /home/yan/Documents/

datais=(`date +%Y-%m-%d---%H-%M-%S`)

git add .
git commit -m "$datais"
git push
