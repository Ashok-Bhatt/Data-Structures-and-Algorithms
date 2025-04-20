#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    public:
        vector<vector<int>> spreadSheet;
    
        Spreadsheet(int rows) {
            this->fillSpreadSheet(rows);
        }
    
        void fillSpreadSheet(int rows){
            for (int i=0; i<rows; i++){
                vector<int> temp(26, 0);
                this->spreadSheet.push_back(temp);
            }
        }
        
        void setCell(string cell, int value) {
            int letter = cell[0] - 'A';
            int digit = 0;
    
            for (int i=1; i<cell.size(); i++){
                digit = digit*10 + cell[i]-'0';
            }
            
            this->spreadSheet[digit-1][letter] = value;
        }
        
        void resetCell(string cell) {
            int letter = cell[0] - 'A';
            int digit = 0;
    
            for (int i=1; i<cell.size(); i++){
                digit = digit*10 + cell[i]-'0';
            }
            
            this->spreadSheet[digit-1][letter] = 0;
        }
        
        int getValue(string formula) {
            int letter1 = -1, letter2 = -1, digit1 = 0, digit2=0;
            int focus = 1;
            for (int i=1; i<formula.size(); i++){
                if (formula[i] >= 'A' && formula[i]<='Z'){
                    if (focus == 1){
                        letter1 = formula[i] - 'A';
                    } else {
                        letter2 = formula[i] - 'A';
                    }
                } else if (formula[i] == '+'){
                    focus = 2;
                } else {
                    if (focus == 1){
                        digit1 = digit1*10 + formula[i]-'0';
                    } else {
                        digit2 = digit2*10 + formula[i]-'0';
                    }
                }
            }

            cout << endl;
            cout << digit1 << " " << digit2 << endl;
    
            int num1 = (letter1 == -1) ? digit1 : this->spreadSheet[letter1][digit1-1];
            int num2 = (letter2 == -1) ? digit2 : this->spreadSheet[letter2][digit2-1];

            return num1+num2;
        }
};

int main(){

    Spreadsheet* sheet = new Spreadsheet(458);
    cout << sheet->getValue("=0126+10272") << endl;

    return 0;
}