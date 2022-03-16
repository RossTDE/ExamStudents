#include <iostream>
#include <string>
using namespace std;

enum pass_status {fail, pass, none};

struct students {
    string name;
    int mark;
    pass_status status = none;
    students* pNext;
};

class List
{
    students* Head;
public:
    List()
    {
        Head = nullptr;
    }
    ~List();
    void Add_Name(string name);
    void print_lst();
    bool add_student(istream& in);
};

List::~List()
{
    while (Head != nullptr)
    {
        students* temp = Head->pNext;
        delete Head;
        Head = temp;
    }
}

void List::Add_Name(string name)
{
    students* temp = new students;
    temp->name = name;
    temp->pNext = Head;
    Head = temp;
}

bool List::add_student(istream& in) {
    string name;
    if (!(in >> name)) return false;
    this->Add_Name(name);
    string status;
    in >> Head->mark;
    in >> status;
    if (status == "none") {
        Head->status = none;
    }
    else if (status == "pass") {
        Head->status = pass;
    }
    else if (status == "fail") {
        Head->status = fail;
    }
    return true;
}

void List::print_lst()
{
    students* temp = Head;
    while (temp != nullptr)
    {
        cout << temp->name << " ";
        cout << temp->mark << " ";
        cout << temp->status << " \n";
        temp = temp->pNext;
    }
}

int main() {
    List lst;
    string name;

    while (lst.add_student(cin));
    lst.print_lst();

}
