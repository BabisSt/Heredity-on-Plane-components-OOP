#include <iostream>
#include <string.h>
#include "classes.h"
using namespace std;


//////////////Class Object//////////

Object::Object()
{
    cout<<"I just constructed an object" << endl;
}

Object::Object(int defid)
{
    id= defid;
    cout << "I just constructed an object with id: " << id << endl ;
}

Object::Object(const Object& s)
{
    id = s.id;
}

Object::~Object()
{
    cout <<"I am deleting an object with id: " << id << endl;
}

void Object::is_equal(const Object& s,const Object& k)
{
    if(s.id==k.id)
    {
        cout<< "These objects are equal" << endl;
    }
    else
    {
        cout <<"These objects are not equal" << endl;   
    }
    
}

void Object::is_identical(const Object& s)
{
    if(s.id==id)
    {
        cout<<"These objects are identical"<<endl;
    }
    else
    {
        cout<<"These objects are not identical"<<endl;
    }
    

}

int Object::get_id()
{
    return id;
}

//////////////////////////////////////////////////

/////////Class String/////////////////////////////

String::String(const char* defstr)
{
    str = new char(strlen(defstr)+1);
    strcpy(str,defstr);
    cout <<"I just constructed a string:"<<str<< endl;
}

String::~String()
{
    cout<<"I am destroying a string:"<<str<< endl;
    delete[] str;

}

String::String(const String& s)
{
    length=s.length;
    str = new char(strlen(s.str)+1);
    strcpy(str,s.str);
    cout <<"I just constructed a string by copying"<<endl;
}

void String:: clear(const char* string)
{
    delete[] string;
}

void String::print_str(const char* string)
{
    cout << string <<endl;
}

int String::get_length(const char* string)
{
    return strlen(str);
}

char* String:: concat(const char* chara,const char* charb,char* result)
{

    strcpy(result,chara); // copy string one into the result.
    strcat(result,charb); // append string two to the result.
    return result;
}

char String::at(char* string,int i)
{
    return string[i];
}

char* String::updateAt(char* string,int i,char a)
{
    string[i]=a;
    return string;
}

void String::toString(const char* string,int len) const
{
    cout <<"The string is:"<<string <<endl;
    cout <<"and its length is:"<<to_string(len)<<endl;
}

//////////////////////////////////////////////////

//////////////Class Plane////////////////////////////
Plane::Plane()
{
    cout<<"I just constructed a plane"<<endl;
}
Plane::Plane(const char* deftitle,const char* defdescription,int defcapacity)
{
    CargoBay* plane_CargoBay;
    EquipmentCompartment *plane_EquipmentCompartment1,*plane_EquipmentCompartment2,*plane_EquipmentCompartment3;
    PassengerCompartment* plane_PassengerCompartment;

    title = new char[strlen(deftitle)+1];
    strcpy(title,deftitle);
    cout<<"I just constructed a plane with title:"<< title << endl;
    
    description = new char[strlen(defdescription)+1];
    strcpy(description,defdescription);

    capacity= defcapacity;

    plane_CargoBay->plane_CargoBay;
    plane_EquipmentCompartment1->plane_EquipmentCompartment;
    plane_EquipmentCompartment2->plane_EquipmentCompartment;
    plane_EquipmentCompartment3->plane_EquipmentCompartment;
}

Plane::Plane(const Plane& s)
{
    title = new char[strlen(s.title)+1];
    strcpy(title,s.title);
    
    description = new char[strlen(s.description)+1];
    strcpy(description,s.description);

    capacity = s.capacity;

    cout<< "I just costructed a plane by copying" <<endl;
}

Plane:: ~Plane()
{
    cout<<"I am destroying a plane"<<endl;
    delete[] title;
    delete[] description;

}

void Plane:: set_capacity_of_plane(int cap)
{   
    PassengerCompartment *plane_PassengerCompartment1,*plane_PassengerCompartment2,*plane_PassengerCompartment3;
    srand(time(0));
    capacity= cap;
    if(capacity>100 && capacity<=200)
    {   
        int r = rand() % 2 + 1; //metaksi 1 kai 2
        if(r==1)
        {
            plane_PassengerCompartment1->plane_PassengerCompartment;
        }
        else
        {
            plane_PassengerCompartment1->plane_PassengerCompartment;
            plane_PassengerCompartment2->plane_PassengerCompartment;
        }
        
    }
    else if(capacity>200)
    {
        int r = rand()% 3 + 1; // metaksi 1 kai 3
        if(r==1)
        {
            plane_PassengerCompartment1->plane_PassengerCompartment;
        }
        else if(r==2)
        {
            plane_PassengerCompartment1->plane_PassengerCompartment;
            plane_PassengerCompartment2->plane_PassengerCompartment;
        }
        else
        {
            plane_PassengerCompartment1->plane_PassengerCompartment;
            plane_PassengerCompartment2->plane_PassengerCompartment;
            plane_PassengerCompartment3->plane_PassengerCompartment;
        }
        
    }
    else
    {
        cout<<"Cannot create a Passenger Compartment"<<endl;
    }
    
}

void Plane:: set_description(const char* defdescription)
{
    description = new char[strlen(defdescription)+1];
    strcpy(description,defdescription);
}

void Plane:: set_title(const char* deftitle)
{
    title = new char[strlen(deftitle)+1];
    strcpy(title,deftitle);
}


char* Plane::get_description()
{
    return description;
}

char* Plane:: get_title()
{
    return title;
}

int Plane:: get_capacity_of_plane()
{
    return capacity;
}

/////////////////////////////////////////////////////

///////////Class PlaneComponent//////////////////////

PlaneComponent::PlaneComponent()
{
    cout << "I just constructed a plane component"<< endl;
}

PlaneComponent::~PlaneComponent()
{
    cout<<"I am destroying a plane component"<< endl;
}

/////////////////////////////////////////////

///////////Class Passenger Compartment/////////

PassengerCompartment::PassengerCompartment()
{
    cout<<"I just constructed a passenger compartment"<<endl;
    srand(time(0));
    int r = rand() % 2;
    if(r==1)
    {
        cout<<"There is an inside passenger compartment"<<endl;
    }
}

PassengerCompartment::~PassengerCompartment()
{
    cout<<"I am destroying a passenger conpartment"<<endl;
}

int PassengerCompartment::process(SecurityEmployee s) const
{
    srand(time(0));
    int r = rand() % 2;
    s.report(r);
    return r;
}

int PassengerCompartment::process(CleaningEmployee s) const
{
    srand(time(0));
    int r = rand() % 2;
    s.report(r);
    return r;

}

void PassengerCompartment::ready_check(int Cp,int Sp) const
{
    if(Cp==1 && Sp==1)
    {
        cout<<"Passenger Compartment is ready"<<endl;
    }
    else
    {
        cout<<"Passenger Compartment is not ready"<<endl;
    }
    
}

/////////////////////////////////////////////

//////////Class PrivateCompartment///////////

PrivateCompartment::PrivateCompartment()
{
    cout<<"I just created a private compartment"<<endl;
}

PrivateCompartment::~PrivateCompartment()
{
    cout<<"I am destroying a private compartment" <<endl;

}

//////////////////////////////////////////////////

///////////////Class Equipment Compartment////////

EquipmentCompartment::EquipmentCompartment()
{
    cout<<"I just created a equipment compartment"<<endl;
}

EquipmentCompartment::~EquipmentCompartment()
{
    cout <<"I am about to destroy an equipment compartment"<<endl;
}


int EquipmentCompartment::process(SecurityEmployee s) const
{
    srand(time(0));
    int r = rand() % 2;
    s.report(r);
    return r;
}


int EquipmentCompartment::process(MaintenanceEmployee s) const
{
    srand(time(0));
    int r = rand() % 2;
    s.report(r);
    return r;
}

void EquipmentCompartment::ready_check(int Sp,int Mp) const
{
    if(Sp==1 && Mp==1)
    {
        cout<<"Equipment Compartment is ready"<<endl;
    }
    else
    {
        cout<<"Equipment Compartment is not ready"<<endl;
    }
    
}
/////////////////////////////////////////////////////

/////////////////Class CargoBay//////////////////////

CargoBay::CargoBay()
{
    cout<<"I just created a cargo bay"<<endl;
    EquipmentCompartment * CargoBay_Equipment;
    CargoBay_Equipment->CargoBay_Equipment;
}

CargoBay::~CargoBay()
{
    cout<<"I am about to destry a cargo bay"<<endl;

}

int CargoBay::process(SecurityEmployee s) const
{
    srand(time(0));
    int r = rand() % 2;
    s.report(r);
    return r;
}

int CargoBay::process(CleaningEmployee s) const
{
    srand(time(0));
    int r = rand() % 2;
    s.report(r);
    return r;
}

int CargoBay::process(MaintenanceEmployee s) const
{
    srand(time(0));
    int r = rand() % 2;
    s.report(r);
    return r;
}

void CargoBay::ready_check(int Sp,int Cp,int Mp) const
{
    if(Sp==1 && Cp==1 && Mp==1)
    {
        cout<<"Cargo Bay is ready"<<endl;
    }
    else
    {
        cout<<"Cargo Bay is not ready"<<endl;
    }
}
//////////////////////////////////////////////////

///////////Class Employee////////////////////////
Employee::Employee()
{
    cout<<"I just constructed an employee"<<endl;
}

Employee::Employee(const char* nam)
{
    name= new char[strlen(nam)+1];
    strcpy(name,nam);
    cout<<"I just costructed an employee with name:"<<name<<endl;
}

Employee::~Employee()
{
    cout<<"I am destroying an employee with name"<<name<<endl;
    delete[] name;
}

void Employee::set_name(const char* nam)
{
    name= new char[strlen(nam)+1];
    strcpy(name,nam);
    cout<<"I just costructed an employee with name:"<<name<<endl;
}

char* Employee::get_name()
{
    return name;
}

//////////////////////////////////////////////////////

///////////Class Security Employee////////////////////

SecurityEmployee::SecurityEmployee(const char* nam)
{
    cout<<"A security employee has just been constructed"<<endl;
}

SecurityEmployee::~SecurityEmployee()
{
    cout<<"I am destroying a security employee"<<endl;
}

void SecurityEmployee::report(int x) const
{
    if(x==1)
    {
        cout<<"This compartment is safe"<<endl;
    }
    else
    {
        cout<<"This compartement is not safe"<<endl;
    }
    
}

void SecurityEmployee::workOn() const
{

}
/////////////////////////////////////////////////////

/////////////Class Maintenance Employee//////////////

MaintenanceEmployee::MaintenanceEmployee(const char* nam)
{
    cout<<"A maintenance employee has just been constructed"<<endl;
}

MaintenanceEmployee::~MaintenanceEmployee()
{
    cout<<"I am destroying a maintenace employee"<<endl;
}

void MaintenanceEmployee::report(int x) const
{
    if(x==1)
    {
        cout<<"This compartment is up to date"<<endl;
    }
    else
    {
        cout<<"This compartement is not up to date"<<endl;
    }
    
}

///////////////////////////////////////////////////////

///////////////Class Cleaning Employee/////////////////

CleaningEmployee::CleaningEmployee(const char*)
{
    cout<<"A maintenance employee has just been constructed"<<endl;
}

CleaningEmployee::~CleaningEmployee()
{
    cout<<"I am destroying a maintenace employee"<<endl;
}

void CleaningEmployee::report(int x) const
{
    if(x==1)
    {
        cout<<"This compartment is clean"<<endl;
    }
    else
    {
        cout<<"This compartement is not clean"<<endl;
    }
    
}

//////////////////////////////////////////////////////////