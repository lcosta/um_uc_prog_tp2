#include "pharmacy.h"

Pharmacy::Pharmacy() {
  
  drugs_count = 0;
  drugs = new Drug*[1];
  
  clients_count = 0;
  clients = new Client*[1];
}

Pharmacy::~Pharmacy() {
}

int Pharmacy::getId() const {
  return id;
}

void Pharmacy::setId(int value) {
  id = value;
}

string Pharmacy::getName() const {
  return name;
}

void Pharmacy::setName(string value) {
  name = value;
}


void Pharmacy::addDrug(Drug *new_drug) {
  drugs[drugs_count] = new_drug;
  drugs_count++;
  expandDrugs();
}

void Pharmacy::editDrug(int id_search, Drug *new_drug) {
  for (int i = 0; i < drugs_count; i++) {
    if (drugs[i]->getId() == id_search) {
      drugs[i] = new_drug;
    }
  }
}

Drug * Pharmacy::getDrugByIdx(int idx) {
  return drugs[idx];
}

void Pharmacy::listDrugs() {
  if (drugs_count > 0) {
    for (int i = 0; i < drugs_count; i++) {
      drugs[i]->print();
    }
  }
  else {
    cout << "\n Não existe ainda medicamentos nesta farmácia.\n";
  }   
}


int Pharmacy::existIdDrugs(int id_search) {
  int match = -1;
  for (int i = 0; i < drugs_count; i++) {
    if (drugs[i]->getId() == id_search) {
      match = i;
    }
  }
  return match;
}


void Pharmacy::addClient(Client *new_client) {
  clients[clients_count] = new_client;
  clients_count++;
  expandClients();
}

void Pharmacy::listClients() {
  if (clients_count > 0) {
    for (int i = 0; i < clients_count; i++) {
      clients[i]->print();
    }
  }
  else {
    cout << "\n Não existe ainda clientes nesta farmácia.\n";
  }   
}


int Pharmacy::existIdClients(int id_search) {
  int match = -1;
  for (int i = 0; i < clients_count; i++) {
    if (clients[i]->getId() == id_search) {
      match = i;
    }
  }
  return match;
}

Client * Pharmacy::getClientByIdx(int idx) {
  return clients[idx];
}

void Pharmacy::editClient(int id_search, Client *new_client) {
  for (int i = 0; i < clients_count; i++) {
    if (clients[i]->getId() == id_search) {
      clients[i] = new_client;
    }
  }
}

void Pharmacy::expandDrugs(){
  Drug ** old = drugs;
  drugs = new Drug*[drugs_count + 1];
  for (int i=0; i < drugs_count; i++) {
    drugs[i] = old[i];
  }
  delete[] old;
}

void Pharmacy::expandClients(){
  Client ** old = clients;
  clients = new Client*[clients_count + 1];
  for (int i=0; i < clients_count; i++) {
    clients[i] = old[i];
  }
  delete[] old;
}


void Pharmacy::writeDrugs(ostream &out){
  cout << "Start Write Drugs:\n";
  for (int i = 0; i < drugs_count; i++) {
    drugs[i]->write(out);
  }
}


void Pharmacy::writeClients(ostream &out){
  cout << "Start Write Clients:\n";
  for (int i = 0; i < clients_count; i++) {
    clients[i]->write(out);
  }
}

void Pharmacy::saveToFile(){
  
  stringstream save_id_str;
  save_id_str << getId();
  
  string str = "db/" + save_id_str.str();
  const char * file_name = str.c_str();
  
  fstream outToFile;
  
  outToFile.open(file_name, ofstream::out|ofstream::trunc);
  if(!outToFile.fail()) {
    outToFile << getName() << "\n";
    outToFile << drugs_count << "\n";
    outToFile << clients_count << "\n";
    writeDrugs(outToFile);
    writeClients(outToFile);
    outToFile.close();
  } 
  else {
    cout << "Error writing to file..." << endl;
  } 
}


void Pharmacy::readFromFile(int open_id){
  
  
  stringstream open_id_str;
  open_id_str << open_id;
  
  string str = "db/" + open_id_str.str();
  const char * file_name = str.c_str();
  
  
  fstream inFromFile;
  
  

  
  inFromFile.open(file_name, ios::in);
  if(!inFromFile.fail()) {
    
    
    string name_f_in_file;
    getline(inFromFile, name_f_in_file);
    setName(name_f_in_file);
    
    
    
    int drugs_count_in_file;
    inFromFile >> drugs_count_in_file;
    
    inFromFile.ignore();
    
    int clients_count_in_file;
    inFromFile >> clients_count_in_file;
    
    
    inFromFile.ignore();
    
    
    
    
    //START: Add Drugs in file
    for (int i= 0; i < drugs_count_in_file; i++) {
      string class_name;
      getline(inFromFile, class_name);

      int id_in_file;
      inFromFile >> id_in_file;
      inFromFile.ignore();
      
      string name_in_file;
      getline(inFromFile, name_in_file);
      
      string laboratory_in_file;
      getline(inFromFile, laboratory_in_file);
      
      
      int day_in_file, month_in_file, year_in_file;
      inFromFile >> day_in_file;
      inFromFile.ignore();
      inFromFile >> month_in_file;
      inFromFile.ignore();
      inFromFile >> year_in_file;
      inFromFile.ignore();
      Date expiration_date_in_file = Date(day_in_file, month_in_file, year_in_file); 
      
      
      float price_in_file;
      inFromFile >> price_in_file;
      inFromFile.ignore();
      
      float pooling_in_file;
      inFromFile >> pooling_in_file;
      inFromFile.ignore();
      
      int quantity_in_file;
      inFromFile >> quantity_in_file;
      inFromFile.ignore();
      
      int stock_in_file;
      inFromFile >> stock_in_file;

      if ( class_name.compare("sachet") == 0 ) {
        int dose_in_file;
        inFromFile.ignore();
        inFromFile >> dose_in_file;
        inFromFile.ignore();
        addDrug(new Sachet(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file,
                           dose_in_file));
        
        
      }
      
      else if ( class_name.compare("syrup") == 0 ) {
        int dose_in_file;
        inFromFile.ignore();
        inFromFile >> dose_in_file;
        inFromFile.ignore();
        string type_of_casing_in_file;
        getline(inFromFile, type_of_casing_in_file);
        
        addDrug(new Syrup(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file,
                           dose_in_file,
                           type_of_casing_in_file));
      }
       
      else if ( class_name.compare("tablet") == 0 ) {
        inFromFile.ignore();
        addDrug(new Tablet(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file));
      }
      
      
      else if ( class_name.compare("varied") == 0 ) {
        inFromFile.ignore();
        addDrug(new Varied(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file));
      }
    }
    //END: Add Drugs in file
    
    //START: Add Clients in file
    for (int i=0; i < clients_count_in_file; i++) {
      int id_c_in_file;
      inFromFile >> id_c_in_file;
      
      inFromFile.ignore();
      
      string name_c_in_file;
      getline(inFromFile, name_c_in_file);
      

      
      
      int age_c_in_file;
      inFromFile >> age_c_in_file;
      
      
      addClient(new Client(id_c_in_file, name_c_in_file, age_c_in_file));
      
      
    }
    //END: Add Clients in file
    
    
    inFromFile.close();
  }
  else {
    cout << "Error reading file..." << endl;
  }
  
}
