class Spreadsheet {
    vector<vector<int>>sheet;
public:
    Spreadsheet(int rows) {
        sheet=vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-65;
        int row=stoi(cell.substr(1));
        sheet[row-1][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-65;
        int row=stoi(cell.substr(1));
        sheet[row-1][col]=0;
    }
    
    int getValue(string formula) {
        int i=1,x=0,y=0;
        if(65<=formula[i] && formula[i]<=90)
        {
            int col=formula[i]-'A';
            i++;
            while(48<=formula[i] && formula[i]<=57) i++;
            int row=stoi(formula.substr(2,i-2));
            x=sheet[row-1][col];
        }
        else {
            while(48<=formula[i] && formula[i]<=57) i++;
            x=stoi(formula.substr(1,i-1));
        }

        i++;

        if(65<=formula[i] && formula[i]<=90)
        {
            int col=formula[i]-'A';
            i++;
            int row=stoi(formula.substr(i));
            y=sheet[row-1][col];
        }
        else {
            y=stoi(formula.substr(i));
        }

        return x+y;
    }
};
