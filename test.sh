#!/bin/bash

./calc1 -matrix ../data/test/1/matrix.dat -vector ../data/test/1/vector.dat -precision double -method qr -pert > logs/1qr.txt
./calc1 -matrix ../data/test/1/matrix.dat -vector ../data/test/1/vector.dat -precision double -method gauss -pert > logs/1gauss.txt
./calc1 -matrix ../data/test/2/matrix.dat -vector ../data/test/2/vector.dat -precision double -method qr -pert > logs/2qr.txt
./calc1 -matrix ../data/test/2/matrix.dat -vector ../data/test/2/vector.dat -precision double -method gauss -pert > logs/2gauss.txt
./calc1 -matrix ../data/test/3/matrix.dat -vector ../data/test/3/vector.dat -precision double -method qr -pert > logs/3qr.txt
./calc1 -matrix ../data/test/3/matrix.dat -vector ../data/test/3/vector.dat -precision double -method gauss -pert > logs/3gauss.txt
./calc1 -matrix ../data/test/4/matrix.dat -vector ../data/test/4/vector.dat -precision double -method qr -pert > logs/4qr.txt
./calc1 -matrix ../data/test/4/matrix.dat -vector ../data/test/4/vector.dat -precision double -method gauss -pert > logs/4gauss.txt
./calc1 -matrix ../data/test/5/matrix.dat -vector ../data/test/5/vector.dat -precision double -method qr -pert > logs/5qr.txt
./calc1 -matrix ../data/test/5/matrix.dat -vector ../data/test/5/vector.dat -precision double -method gauss -pert > logs/5gauss.txt