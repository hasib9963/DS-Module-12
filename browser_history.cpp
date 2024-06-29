#include<bits/stdc++.h>
using namespace std;
int main() {
    list<string> List;
    string website;
    while(cin >> website) {
        if(website == "end") 
        break;
        List.push_back(website);
    }
    int q;
    cin >> q;
    auto litm = List.begin();
    while(q--) {
        string wb;
        cin >> wb;
        if(wb == "visit") {
            cin >> wb;
            auto litm2 = find(List.begin(), List.end(), wb);
            if(litm2 == List.end()) 
            {
                cout << "Not Available"<<endl;
            }
            else {
                litm  = litm2;
                cout << *litm  << endl;
            }
        } else if(wb == "next") {
            litm ++;
            if(litm  == List.end()) {
                cout << "Not Available"<<endl;
                litm --;
            } else cout << *litm  << endl;
        } else if(wb == "prev") {
            if(litm  == List.begin()) {
                cout << "Not Available"<<endl;
            } else {
                litm --;
                cout << *litm  << endl;
            }
        }
    }
    return 0;
}