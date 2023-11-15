#include <bits/stdc++.h>
using namespace std;

class Memory{
protected:
    int memory[256] ,reg[16] ;
    int count,start;
    int N,R,XY,NR,X,Y;
};

class Run : Memory{
public:
    void Run_program_step(){
        for (count=start ;count<256; ){
            int i=count;
            NR =memory[i];
            R=NR&15;
            N=NR>>4;
            XY =memory[i+1];
            count=Processing(count , N);
            NR = NR << 8 ;
            NR |= XY ;
            cout << "instructionRegister : " <<hex<< NR<<"\tProgram_count : " << hex << count  << endl ;
        }
    }
    void Run_program(){
        for (count=start ;count<256; ){
            int i=count;
            NR =memory[i];
            R=NR&15;
            N=NR>>4;
            XY =memory[i+1];
            count=Processing(count , N);
        }
    }
    vector<int>v;
    void print(){
    for (int i = 0; i <v.size(); i++) {
        cout << dec << "DEC : " << memory[0]  << ", HEX : " << hex << memory[0] << endl;
    }
    }
    int Processing(int prog_count , int cas){
        switch (cas) {
            case 1:
                reg[R] =memory[XY];
                break;
            case 2:
                reg[R] = XY;
                break;
            case 3:
                if(XY == 0){
                    memory[XY]=reg[R];
                    v.push_back(memory[0]);
                    break;
                }
                memory[XY]=reg[R];
                break;
            case 4:
                reg[XY&15]=reg[(XY>>4)]; 
                break;
            case 5:
                Y= XY&15;
                X = XY>>4;
                reg[R]=reg[X]+reg[Y];
                break;
            case 11:
                if (reg[R] == reg[0]){
                    return prog_count = XY;
                }
                break;
            case 12:
                return 256;
        }
        return prog_count+2;
    }

    void Start_Address(int sta){
        start = sta;
    }
    void Mem_Address(int &st , int vl){
        memory[st] = vl;
    }
    friend void File (string name , Run& pr);
};

void File(string name , Run& pr1){
    name += ".txt";
    ifstream file(name);
    int num , st ;
    file >> hex >> st ;
    pr1.Start_Address(st);
    while (file >> hex >> num) {
        int xy , nr ;
        xy = (255 & num);
        num = num >> 8;
        nr = num;
        pr1.Mem_Address(st , nr);
        st++;
        pr1.Mem_Address(st , xy );
        st++;
    }
    file.close();
}


int main() {
    string name ;
    cout << "Please enter name of file :";
    cin >> name ;
    Run prog;
    File(name,prog);
    cout<<"1-run all instructionRegister"<<endl;
    cout<<"2-run instructionRegister step by step"<<endl;
    int n;cin>>n;
    if(n==1)prog.Run_program();
    if(n==2) prog.Run_program_step();
    prog.print();

    return 0;
}
