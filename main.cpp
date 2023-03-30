#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int hang;
    int yeol;
    int randomNumber;
    int nigga = 0;
    int niggano = 1;
    
    cout << "[>] 행을 입력해 주세요: ";
    cin >> hang;
    
    cout << "[>] 열을 입력해 주세요: ";
    cin >> yeol;
    
    cout << "[>] 학생 수를 입력해 주세요: ";
    cin >> nigga;
    
    cout << "\n";
    
    std::list<int> numbers;
    
    while (niggano != nigga){
        randomNumber = rand() % nigga + 1;
        auto iter = std::find(numbers.begin(), numbers.end(), randomNumber);
        if (!(iter != numbers.end())){
            numbers.push_back(randomNumber);
            niggano += 1;
        }
    }
    
    niggano = 0;
    
    cout << "[*] 설정된 학생 수: " << nigga << "\n\n";
        
    for (uint n = 1; n <= yeol; n++){
        cout << "[" << n << "] ";
        for (uint i = 1; i <= hang; i++){
            if (niggano == nigga){
                break;
            }
            auto cnm = std::next(numbers.begin(), niggano);
            
            if (i < hang){
                if (*cnm < 10){
                    cout << *cnm << "   ";
                }
                else{
                    cout << *cnm << "  ";
                }
            }
            else if (i == hang){
                cout << *cnm << "\n";
            }
            
            niggano += 1;
        }
    }
    cout << "\n";
    
    return (0);
}
