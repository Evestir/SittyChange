#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <unordered_set>

using namespace std;

std::list<int> numbers;

bool deterInt(int num){
    int i = 0;
    
    while (i < numbers.size()){
        auto cnm = std::next(numbers.begin(), i);
        if (num == *cnm){
            return true;
        }
        
        i++;
    }
    
    return false;
}

int main() {
    int hang;
    int yeol;
    int randomNumber;
    int pup = 0;
    int coc = 1;
    
    cout << "[>] 행을 입력해 주세요: ";
    cin >> hang;
    
    cout << "[>] 열을 입력해 주세요: ";
    cin >> yeol;
    
    cout << "[>] 학생 수를 입력해 주세요: ";
    cin >> pup;
    
    cout << "\n";
    
    std::list<int> blacklist = { 23 };
    std::list<int> whitelist = { 32, 35 };
            
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, pup);
    
    while (coc <= pup){
        randomNumber = dis(gen);
        
        if (deterInt(randomNumber) == false){
            cout << "Added " << randomNumber << " to the list. \n";
            numbers.push_back(randomNumber);
            coc++;
        }
    }
    
    coc = 0;
    
    cout << "[*] 설정된 학생 수: " << pup << "\n\n";
            
    for (uint n = 1; n <= yeol; n++){
        cout << "[" << n << "] ";
        for (uint i = 1; i <= hang; i++){
            if (coc == pup){
                break;
            }
            auto cnm = std::next(numbers.begin(), coc);
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
            
            coc++;
        }
    }
    
    cout << '\n';
    
    return (0);
}
