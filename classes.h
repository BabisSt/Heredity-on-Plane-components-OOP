class CargoBay;
class EquipmentCompartment;
class PassengerCompartment;
class Employee;
class SecurityEmployee;
class CleaningEmployee;
class MaintenanceEmployee;



class Object
{
private:
    int id;
   
public:
    Object();
    Object(const int);
    Object(const Object&);
    virtual ~Object();

    virtual void is_equal(const Object&,const Object&);
    virtual void is_identical(const Object&);
    virtual void toString(const char*,int) const =0;

    int get_id();
};

class String : public Object
{
private:
    char* str;
    int length;
public:
    String(const char*);
    virtual ~String();
    String(const String &s);

    void clear(const char*); 
    void print_str(const char*);
    
    int get_length(const char*);
    char* concat(const char*,const char*,char*);
    char at(char*,int);
    char* updateAt(char*,int,char);

    virtual void toString(const char*,int) const ;
};


class Plane : public Object
{
private:
    char* description;
    char* title;
    int capacity;
    CargoBay* plane_CargoBay;
    EquipmentCompartment* plane_EquipmentCompartment;
    PassengerCompartment* plane_PassengerCompartment;

public:
    Plane();
    Plane(const char*,const char*,int);
    Plane(const Plane&);
    virtual ~Plane();

    void set_capacity_of_plane(int);
    void set_description(const char*);  
    void set_title(const char*);        

    char* get_description();
    char* get_title();
    int get_capacity_of_plane();
};


class PlaneComponent : public Plane
{  
public:
    PlaneComponent();
    virtual ~PlaneComponent();

    virtual int process(SecurityEmployee) const =0;
    virtual int process(CleaningEmployee) const =0;
    virtual int process(MaintenanceEmployee) const =0;
    virtual void ready_check(int,int,int)const = 0;

    
};

class PassengerCompartment : public PlaneComponent
{

public:
    PassengerCompartment();
    virtual ~PassengerCompartment();

    virtual void ready_check(int,int)const;
    virtual int process(SecurityEmployee) const;
    virtual int process(CleaningEmployee) const;
};

class PrivateCompartment : public PlaneComponent
{
public:
    PrivateCompartment();
    virtual~PrivateCompartment();

    virtual void ready_check() const;
    virtual int process(SecurityEmployee) const;
    virtual int process(CleaningEmployee) const;
};

class EquipmentCompartment : public PrivateCompartment
{
public:
    EquipmentCompartment();
    virtual ~EquipmentCompartment();
    EquipmentCompartment * CargoBay_Equipment;

    virtual void ready_check(int,int) const;
    virtual int process(SecurityEmployee) const;
    virtual int process(MaintenanceEmployee) const ;  
};

class CargoBay : public PrivateCompartment
{
public:
    CargoBay();
    virtual ~CargoBay();


    virtual void ready_check(int,int,int) const ;
    virtual int process(SecurityEmployee) const ;
    virtual int process(CleaningEmployee) const ;
    virtual int process(MaintenanceEmployee) const ;   
};


class Employee 
{
private:
    char* name;
public:
    Employee();
    Employee(const char*);
    virtual ~Employee();

    virtual void report(int) const = 0;
    virtual void workOn() const = 0;
    void set_name(const char*);
    char* get_name();
};

class SecurityEmployee : public Employee
{    
public:
    SecurityEmployee(const char*);
    virtual ~SecurityEmployee();
    virtual void report(int) const ;
    virtual void workOn() const ; //pantou
};

class MaintenanceEmployee : public Employee
{
public:
    MaintenanceEmployee(const char*);
    virtual ~MaintenanceEmployee();
    
    virtual void report(int) const ;
    virtual void workOn() const ; //cargo,equip
};

class CleaningEmployee : public Employee
{

public:
    CleaningEmployee(const char*);
    virtual ~CleaningEmployee();
    virtual void report(int) const ;
    virtual void workOn() const ;//passenger,cargo
};
