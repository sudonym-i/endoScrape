#include <fstream>
#include <iostream>

const int MAX_LINE = 512;
const int MAX_FILE_SIZE = 1024;

struct Point{
    char symptoms_dur[MAX_LINE];
    char age[MAX_LINE];
    char location[MAX_LINE];
    char date[MAX_LINE];
    char symptoms[MAX_LINE];
    char symptoms_desc[MAX_LINE];
    char treatments[MAX_LINE];
};

struct Node{
public:
    Node * Next;
    Point Subset;
private:  
};
void terminal_print(std::ostream &out, Node *head);

int main(){
    char garbage_line[MAX_LINE];
    char garbage, past;
    Node *head = new Node;
    std::ifstream data("data.txt");
    Node *current = head;

    while(data.getline(garbage_line, MAX_LINE)){
        data.getline(current->Subset.symptoms_dur, MAX_LINE);
        data.getline(current->Subset.age, MAX_LINE);
        data.getline(current->Subset.location, MAX_LINE);
        data.getline(current->Subset.date, MAX_LINE);
        while ( (garbage != '\n') || (data.get(garbage) != '\n') ); // currently discarding description (Checks for double endl)
        data.getline(current->Subset.symptoms, MAX_LINE);
        data.getline(current->Subset.symptoms_desc, MAX_LINE);
        data.getline(current->Subset.treatments, MAX_LINE);
        current->Next = new Node;
        current = current->Next;
    }
    terminal_print(std::cout, head);
    return 0;
}

void terminal_print(std::ostream &out, Node *head){
    Node *current = head;
    while(current != nullptr){
        out << "\nSymptoms_dur: " << current->Subset.symptoms_dur 
        << "\n Age: " << current->Subset.age << " \nLocation: " 
        <<  current->Subset.symptoms_dur << std::endl;
        current = current->Next;
    }
}
