/**
 * @file mat.cpp
 * @author Raz Gavrieli (razgavrieli@gmail.com)
 * @brief This file is used to satisfy an assigment given at a cpp course, Ariel University.
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <iostream>
#include "mat.hpp"

#include <vector>
using namespace std;

vector<vector<int>> mat2arr(int w, int h, vector<vector<int>> arr)

/**
 * @brief 
 * gets width and height of the mat, and creates an array containing zeros and ones. 
 * The zeros present char a, and the ones present chat b. 
 */
{
    int k = 0;
    bool symflag = true;
    while (k<=w/2||k<=h/2) 
    {
        for (int j=k; j<w-k; j++) {
            if (symflag && h-k>0) {
                arr[k][j] = 1;}
            else if (h-k>0){
                arr[k][j] = 0;}
        }
        for (int i=k; i<h-k; i++) {
            if (symflag && w-k>0){
                arr[i][w-k-1] = 1;}
            else if (w-k>0){
                arr[i][w-k-1] = 0;}
        }
        for (int j=w-k-1; j>=k; j--) {
            if (symflag && h-k>0) {
                arr[h-1-k][j] = 1;}
            else if (h-k>0){
                arr[h-1-k][j] = 0;}
        }
        for (int i=h-k-1; i>=k; i--) {
            if (symflag && w-k>0) {
                arr[i][k] = 1; }
            else if (w-k>0) {
                arr[i][k] = 0;}
        }

        symflag = !symflag; //flip "symflag" - symbol symflag. 
        k++;
    }
        return arr;
}

namespace ariel {
    std::string mat(int w, int h, char a, char b)
    {
        /**
         * @brief 
         * gets width and height of the mat, creates a new matrix (2d array) 
         * and assign each cell to each correct value. 
         * Then, iterate through the array and create a string that represnts it.
         * Return the string. 
         */
        /*check input*/
        if (w%2==0||h%2==0) {
            throw std::runtime_error("Mat size is always odd");
        }
        if (w<=0||h<=0) {
            throw std::runtime_error("Mat size is always positive");
        }
        // if (a==b) {
        //     throw std::runtime_error("Mat has to contain 2 different symbols");
        // }
        const short asciiinf = 33;
        const short asciisup = 126;
        if (a<asciiinf||a>asciisup||b<asciiinf||b>asciisup) {
            throw std::runtime_error("Mat can't contain special characters");
        }
        std::string res;
        if (w==1&&h==1) {
            res+=a;
            return res;
        }

        // Memory allocation for new array
        // int **arr = nullptr; 
        // arr = new int*[h];
        // for (int i = 0; i < h; i++) {
        //     arr[i] = new int[w]; }

        vector<vector<int>> arr(h, vector<int>(w));
        
        arr = mat2arr(w, h, arr);

        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (arr.at(i).at(j)==1) {
                    res += a; }
                else {
                    res += b; }
            }
            res += "\n";
        }
        return res;
    }
}