#include<vector>
#include<iostream>

using namespace std;

/*
Problem 273 from Leetcode solved with C++
*/
string digitsToString(int n, const vector<string>& ones_map, const vector<string>& tens_map);
/* (1) This function converts to english words every group of 3 numbers (1-999), which are between commas (,) 
and appends its dimension: thousand, million, billion.
(2) Once one can read correctly a number from 1 to 999, it is easy to read numbers from higher orders.
*/
 string numberToWords(int num) {
        
    vector<string> ones_map = {"", "One","Two","Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen","Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    vector<string> tens_map  = {"", "", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy", "Eighty", "Ninety"};

    vector<string> thousands_map = {"", "Thousand", "Million", "Billion"};

    if (num==0){
        return "Zero";
    }

    string words;
    int group = 0;

    while (num>0){
        int current = num % 1000;
        if (current>0){
            string temp = digitsToString(current, ones_map, tens_map);
            if (group>0){
                temp = temp + " " + thousands_map[group];
            }
            if (!words.empty()){
                temp = temp + " ";
            }
            words = temp + words;
        }
        num = num / 1000;
        group++;
    }  
    return words;
}

string digitsToString(int n, const vector<string>& ones_map, const vector<string>& tens_map){
    /* this functions converts to string any number from 1 to 999*/
    string s = "";

    if (n>=100){
        s = s + ones_map[n/100] + " Hundred";
        n = n % 100;
        if (n>0){
            s = s + " ";
        }
    }
    if (n>=20){
        s = s + tens_map[n/10];
        n = n % 10;
        if (n>0){
            s = s+ " ";
        }
    }
    if (n<20){
        s = s + ones_map[n];
    }
    return s;
}

int main() {
    /* Testing for number 12,345,789*/
    int num = 12345789;
    string word = numberToWords(num);
    cout << "Number in English: " << word << endl;
    return 0;
}

