#!/bin/bash
datais=(`date +%Y-%m-%d---%H-%M-%S`)
git add .
git commit -m "$datais"
git push
