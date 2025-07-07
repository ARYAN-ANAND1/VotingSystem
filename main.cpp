#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;
#define aryananand ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

class Candidate {
public:
    int id;
    string name;
    string party;
    int votes;

    Candidate(int id, const string &name, const string &party) {
        this->id = id;
        this->name = name;
        this->party = party;
        this->votes = 0;
    }

    void display() const {//For Read_Only Function
        cout<<"ID: "<<id<<" | Name: " <<name<<" | Party: " <<party<<" | Votes: "<<votes<<"\n";
    }
};

class VotingSystem {
private:
    vector<Candidate> candidates;
    map<int, int> idToIndex; // candidate ID to index in vector
    set<int> votedVoters;    // to prevent double voting

public:
    void loadCandidatesFromFile(const string &filename) {
        ifstream file(filename);
        if(!file.is_open()) 
        {
            cerr<<"Error: Unable to open"<<filename<<"\n";
            exit(1);
        }

        string line;
        while(getline(file,line)) 
        {
            stringstream ss(line);
            string idStr,name,party;

            if (!getline(ss,idStr, '|'))continue;
            if (!getline(ss,name, '|'))continue;
            if (!getline(ss,party))continue;
            addCandidate(stoi(idStr), name, party);
        }
        file.close();
    }

    void addCandidate(int id, const string &name, const string &party) {
        idToIndex[id]=candidates.size();
        candidates.emplace_back(id, name, party);
    }

    void displayCandidates() const {
        cout << "\n--- Candidate List ---\n";
        for (const auto &c : candidates) {
            c.display();
        }
    }

    void castVote(int voterID, int candidateID) {
        if (votedVoters.count(voterID)) {
            cout << "You have already voted!\n";
            return;
        }
        if (idToIndex.find(candidateID) == idToIndex.end()) {
            cout << "Invalid candidate ID!\n";
            return;
        }

        candidates[idToIndex[candidateID]].votes++;
        votedVoters.insert(voterID);
        cout<<"Your vote has been recorded.\n";
    }

    void showResults() const {
        cout << "\n--- Voting Results ---\n";
        int maxVotes = -1;
        vector<string> winner;

        for (const auto &c : candidates) {
            c.display();
            if(c.votes > maxVotes) 
            {
                maxVotes = c.votes;
                winner.clear();
                winner.push_back(c.name);
            } 
            else if(c.votes==maxVotes)winner.push_back(c.name);
            
        }

        cout << "\n--- Winner(s): ";
        for (const auto &name : winner) {
            cout<<name << " ";
        }
        cout << "---\n";
    }
};

int main() {
    aryananand;
    VotingSystem vs;
    vs.loadCandidatesFromFile("candidates.txt");

    int choice;
    cout<<"=== Welcome to the Voting System ===\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. View Candidates\n";
        cout << "2. Cast Vote\n";
        cout << "3. Show Results\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin>>choice;

        if(choice==1) 
        {
            vs.displayCandidates();
        } 
        else if(choice==2) 
        {
            int voterID, candidateID;
            cout << "Enter your Voter ID: ";
            cin >> voterID;
            cout << "Enter Candidate ID to vote: ";
            cin >> candidateID;
            vs.castVote(voterID, candidateID);
        } 
        else if (choice == 3) 
        {
            vs.showResults();
        } 
        else if(choice==4) 
        {
            cout << "Thank you for voting. Have a nice Day!\n";
            break;
        } 
        else 
        {
            cout<<"Invalid choice. Try again.\n";
        }
    }
    return 0;
}
