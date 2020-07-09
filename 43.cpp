class Solution {
public:
    string digitmul(string s1, string s2, string c){
        assert(s1.size()==1 && s2.size()==1);
        int d1 = std::stoi(s1);
        int d2 = std::stoi(s2);
        int d3 = std::stoi(c);
        string s3 = std::to_string(d1*d2+d3);
        return s3;
    }
    string digitadd(string s1, string s2, string c){
        assert(s1.size()==1 && s2.size()==1);
        int d1 = std::stoi(s1);
        int d2 = std::stoi(s2);
        int d3 = std::stoi(c);
        string s3 = std::to_string(d1+d2+d3);
        return s3;
    }
    string carry(string s){
        if(s.size() == 1)
            return "0";
        return s.substr(0,1);
    }
    string noncarry(string s){
        if(s.size() == 1)
            return s.substr(0,1);
        return s.substr(1,1);
    }
    string multiply(string num1, string num2) {
        string res(256, '0');
        string ca = "0";
        int lsp = 255;
        for(int j = num2.size()-1; j>=0;--j){
            for(int i = num1.size()-1;i>=0;--i){
                int pos = lsp-num1.size()+i+1;
                string tmul = digitmul(num1.substr(i,1),num2.substr(j,1), ca);
                string ca1 = carry(tmul);
                string tadd = digitadd(noncarry(tmul), res.substr(pos, 1), "0");
                ca = digitadd(ca1, carry(tadd), "0");
                res[pos] = noncarry(tadd)[0];
            }
            // clear ca
            while(ca != "0"){
                int pos = lsp-num1.size();
                string tadd = digitadd("0", res.substr(pos, 1), ca);
                res[pos] = noncarry(tadd)[0];
                ca = carry(tadd);
            }
            ca = "0";
            lsp--;
        }
        int index = 0;
        for(;index<255 && res[index]=='0'; ++index);
        return res.substr(index, 256-index);
    }
};