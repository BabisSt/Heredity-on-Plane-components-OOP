# Heredity on Plane components OOP


ΑΣΚΗΣΗ 3η ΑΝΤΙΚΕΙΜΕΝΟΣΤΡΑΦΗΣ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ
ΑΜ: 1115201600278
Στεβής Χαράλαμπος-Αντώνιος

Τα αρχεία που περιέχονται στον φάκελο είναι τα εξής:
classes.h		//οι επικεφαλίδες
classes.cpp	//οι υλοποιήσεις
Μεταγλώτηση μέσω g++ -c classes.cpp


Σε αυτά τα αρχεία υπάρχουν οι εξής κλάσεις:<br/>
Object<br/>
String<br/>
Plane<br/>
Plane Compartment<br/>
Passenger Compartment<br/>
Private Compartment<br/>
Equipment Compartment<br/>
Cargo Bay<br/>
Employee<br/>
Security Employee<br/>
Maintenance Employee<br/>
Cleaning Employee<br/>

Η κληρονομικότητα είναι η εξής:<br/>

Object(πατέρας,όλα είναι παιδιά του)<br/>
	Plane(πατέρας όλων των υπολοίπων)<br/>
		PlaneCompartment<br/>
			PassengerCompartment - PrivateCompartment<br/>	
						EquipmentCompartment - CargoBay<br/><br/>


Employee<br/>
Security-Maintenance-Cleaning<br/>


Η κλάση Object περιέχει τα εξής:
	private: id	
	
	Constructor
	Constructor με όρισμα id
	Copy Constructor
	virtual Destructor

	virtual is_equal ( όρισμα δύο objects και τα συγκρίνει αν είναι ίδια ή οχι,εκτυπώνει το ανάλογο μήνυμα)
	virtual is_identical( όρισμα ένα object και το συγκρίνει με το id,εκτυπώνει το ανάλογο μήνυμα)
	pure virtual toString(όρισμα ενα char* και ένα int)
	int get_id (επιστρέφει το id)

Η κλάση String περιέχει τα εξής:
private: char* str / int length

	Constructor με όρισμα str
	Copy Constructor όρισμα String
	virtual Destructor

	void clear(με όρισμα ένα char* και το διαγράφει)
	void print_str(με όρισμα ένα char* και το εκτυπώνει)
	int get_lenght(με όρισμα ένα char* και εκτυπώνει το μέγεθος μέσω strlen)
	char* concat(με ορίσματα τρία char*, τα δύο που θέλουμε να ενώσουμε και ακόμα ένα που θα είναι το αποτέλεσμα,γίνεται μέσω strcpy και strcat)
	char at(με ορίσματα ένα char και ένα int,γυρνάει το στοιχείο του char* στο σημείο του int)
	char* updateAt(ορίσματα char*,int,char,βάζει στο char* στο σημείο του int 
το στοιχείο char)
	void toString(ορίσματα char*,int, εκτυπώνει το char* και το length του string σε μορφή char)


Η κλάση Plane περιέχει τα εξής:
private:	char* description,title
			int capacity
			CargoBay*
			EquipmentCompartment*
			PassengerCompartment*

	Constructor
	Constructor με ορίσματα(συν οι χώροι του αεροπλάνου)
	Copy Constructor
	virtual Destructor

	void set_capacity_of_plane(όρισμα ένα int και ανάλογα δημιουργεί passengerc compartments τυχαία ανάλογα την χωριτηκότητα)
	void set_description(όρισμα ένα char*)
	void set_title(όρισμα ενα char*)
	char* get_description
	char* get_title
	char* get_capacity_of_plane


Η κλάση PlaneCompartment περιέχει τα εξής:

	Constructor
	virtual Destructor
	pure virtual process(3, μια για κάθε τύπο employee)
	pure virtual ready_check(ορίσματα 3 int)

Οι κλάσεις PassengerCompartment,PrivateCompartment,EquipmentCompartment και CargoBay περιέχουν τα εξής:

	Constructor(στο Passenger υπάρχει δυνατότητα δημιουργίας εσωτερικού passengercompartment με τυχαίο τρόπο,στον Cargobay υπάρχει ένα equipment compartment)
	virtual Destructor
	
	virtual ready_check(με ορίσματα από δύο μέχρι τρεις int,δέχεται τα αποτελέσματα από τις process και αν είναι όλα άσσοι εκτυπώνει οτι το compartment είναι έτοιμο, αντιθέτως εκτυπώνει ότι δεν είναι έτοιμο)
	virtual process(από δύο μέχρι τρεις,με όρισμα τον ανάλογο τον employee,μέσω rand καθορίζει αν ο employee έκανε την δουλεία του, μέσα καλεί την report του employee)


Η κλάση Employee περιέχει τα εξής:
private: char* name

	Constructor
	Constructor με ορισμα char*
	virtual Destructor
	
	virtual report(όρισμα ενα int)
	virtual workOn
	void set_name(όρισμα ενα char*)
	char* get_name

	Οι κλάσεις SecurityEmployee,MaintenanceEmployee και CleaningEmployee περιέχουν τα εξής:

	Constructor με όρισμα char*
	virtual Destructor

	virtual report(όρισμα ενα int,δέχεται εναν αριθμό,αν είναι 1 εκτυπώνει το αναλόγο μήνυμα ότι το compartment είναι εντάξει,διαφοτερικά εκτυπώνει το αντοίστιχο αρνητικό μήνυμα)
	virtual workOn(δεν είναι υλοποιημένη)

Στην εργασία δεν υπάρχει main επειδή δεν πρόλαβα να την υλοποιήσω.
Δεν υπάρχει η συνάρτη clone_encrypt_and_print
Δεν υπάρχει η συνάρτη workOn των employee
