#include <iostream>
#include <vector>
#include <any>
#include <variant>
#include <cassert>
using namespace std;

vector<string> types = ["string","number","vpn","bool"]

bool isAinTypes( string A){
    for (i==0; i <types.size(), i=i+1){
        if (A == B[i]){
            return true
        }
    }
    return false
}


bool typeCheck(string A, string B) {
    return (A==B || B=="any")
}
struct Error {
    string Header;
    vector<any> body;
    int code;
};

struct Value {
    string type;
    void* store;
};

struct Variable{
    string name;
    void* value;
    string rtype;
}

class Scope{
    public:
        string text;
        vector<Variable> variables;
        void translate(){
            for (i == 0; i < text.size(), i= i + 1) {
                string c = text.substr(i,1);
                if (c=="\n") {
                    text.replace(c,1,";");
                }
            }
        };
        void* interpert(){
            string lineHeader = getToken();
            if (lineHeader == "sc"){
                string name = getToken();
                string rtype = "any";
                if isAinTypes(name){
                    rtype = name;
                    name = getToken();
                }
                string eq = getToken();
                if (eq == "="){
                    string restOfLine = evalUntil(";");
                    void* value = inlineEval(restOfLine);
                    if (!typeCheck(value,rtype)){
                        error("Cannot convert types!")
                        return false
                    }
                    Variable var;
                    var.name = name;
                    var.value = value;
                    var.rtype = rtype;
                    variables.push(var);
                }else if (eq=="("){
                    Scope scope;
                    while (true){
                        name = getToken();
                        if (name == ")") {
                            break;
                        }
                        Variable v1;
                        v1.name = name;
                        if isAinTypes(v1.name){
                            v1.rtype = v1.name;
                            v1.name = getToken();
                        };
                    }
                }else {
                    error("Invalid declaration!")
                    return false
                }
            }
        };
        void error(string str){
            cout<<str
        }
};