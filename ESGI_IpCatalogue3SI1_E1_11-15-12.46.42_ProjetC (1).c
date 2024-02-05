
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define FILENAME "IPDatabase.txt"

char globalIP[16];
char globalSubnetMask[16];

void AddIP();
void MenuAddIP();
void Menu();
void EndProgram();
bool ValidationIP();
void MenuListIPSubnet();
void MenuListIPAll();
void BeginProgram();
bool IsIPAddressValid(char* ip);
bool IsIPMaskValid(char subMask[16]);
void SearchIP();
void MenuIPInvalid();
char* getIP();
char* getSubnetMask();
void setIP(char iP[16]);
void setSubnetMask(char subnetMask[16]);
void Conversion();
bool InBDD(char ip[16], char subnetMask[16]);
void PrintAllIP();


int main(int argc, char const *argv[])
{
    BeginProgram();
    return 0;
}

/**
 * Insert 76 IP if the database if the file is empty (for the test)
*/
void Insert76IP(){
    FILE* fileIP = fopen(FILENAME, "w");
    if (fileIP == NULL) {
        perror("**ERROR** Can't open database\n");
        exit(EXIT_FAILURE);
    }

    char BDDIP[][16] = {
    "192.168.1.1",
    "192.168.1.2",
    "192.168.1.247",
    "192.168.1.105",
    "192.168.1.146",
    "192.168.1.66",
    "192.168.1.222",
    "192.168.1.145",
    "192.168.1.165",
    "192.168.1.77",
    "192.168.1.249",
    "192.168.1.80",
    "192.168.1.217",
    "192.168.1.240",
    "192.168.1.183",
    "192.168.1.75",
    "192.168.1.85",
    "192.168.1.115",
    "192.168.1.36",
    "192.168.1.207",
    "192.168.1.73",
    "192.168.1.65",
    "192.168.1.130",
    "192.168.1.223",
    "192.168.1.11",
    "192.168.1.178",
    "192.168.1.118",
    "192.168.1.210",
    "192.168.1.138",
    "192.168.1.6",
    "192.168.1.1",
    "192.168.1.60",
    "192.168.1.206",
    "192.168.1.196",
    "192.168.1.56",
    "192.168.1.89",
    "192.168.1.139",
    "192.168.1.237",
    "192.168.1.71",
    "192.168.1.246",
    "192.168.1.92",
    "192.168.1.29",
    "192.168.1.6",
    "192.168.1.87",
    "192.168.1.99",
    "192.168.1.49",
    "192.168.1.117",
    "10.17.34.76",
    "10.17.34.180",
    "10.17.34.158",
    "10.17.34.48",
    "10.17.34.157",
    "10.17.34.206",
    "10.17.34.61",
    "10.17.34.209",
    "10.17.34.24",
    "10.17.34.152",
    "10.17.34.58",
    "10.17.34.152",
    "10.17.34.118",
    "10.17.34.126",
    "10.17.34.144",
    "10.17.34.198",
    "10.17.34.125",
    "10.17.34.178",
    "10.17.34.217",
    "10.17.34.191",
    "10.17.34.130",
    "10.17.34.198",
    "10.17.34.245",
    "10.17.34.77",
    "10.17.34.170",
    "10.17.34.127",
    "10.17.34.90",
    "10.17.34.131",
    "10.17.34.57",
    "10.17.34.142"
    };
    
    char BDDSubnetMask[][16] = {
        "255.0.0.0",
        "255.255.0.0",
        "255.255.255.0",
        "255.255.255.252"
    };

    for (int i = 0; i < sizeof(BDDIP) / sizeof(BDDIP[0]); i++) {
        fprintf(fileIP, "%s     %s\n", BDDIP[i], BDDSubnetMask[i % 4]);
    }

    fclose(fileIP);
}

/**
 * Read the file -> if empty, charge IP with the function Insert76IP
*/
void ReadIPFile() {
    FILE *fileIP = fopen(FILENAME, "r");
    if (fileIP == NULL) {
        perror("File empty. Generation of IP for test.\n");
        Insert76IP();
        return;
    }
    fclose(fileIP);
}


/**
 * Beginning of the program
*/
void BeginProgram(){
    printf("****************************************************************************************************************************************************\n");
    printf("****************************************************************************************************************************************************\n");
    printf("      *******  #######  ######          #######        ###      #######       ###       ##        #######  ######    ##   ##  #######  *******      \n");
    printf("     *******     ###    ##   ##         ##            ## ##       ###        ## ##      ##        ##   ##  ##  ###   ##   ##  ##        *******     \n");
    printf("                 ###    ##   ##         ##           ##   ##      ###       ##   ##     ##        ##   ##  ##        ##   ##  ##                    \n");
    printf("    *******      ###    #####   ~~~~~~~ ##          #########     ###      #########     ##       ##   ##  ##        ##   ##  ####       *******    \n");
    printf("                 ###    ##              ##         ##       ##    ###     ##       ##    ##       ##   ##  ## #####  ##   ##  ##                    \n");
    printf("     *******     ###    ##              ##        ##         ##   ###    ##         ##   ##       ##   ##  ##   ###  ##   ##  ##        *******     \n");
    printf("      *******  #######  ##              #######  ##           ##  ###   ##           ##  #######  #######  #######   #######  #######  *******      \n");
    printf("****************************************************************************************************************************************************\n");
    printf("****************************************************************************************************************************************************\n\n\n");

    ReadIPFile();

    printf("\n\n");

    Menu();
}

/**
 * 
 * Display the Main Menu
*/
void Menu(){
    printf("                        Welcome to Main Menu                            \n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$ Main Menu *$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*\n");
    printf("1 - Add a new IP address\n");
    printf("2 - List IP addresses\n");
    printf("3 - Search IP addresses from same subnet\n");
    printf("4 - Hexadecimal, Binary, Decimal\n");
    printf("5 - Quit\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n\n");

    int choice;
    printf("Make a choice : ");
    scanf("%d", &choice);

    bool state = false;
    while (!state)
    {
        switch (choice)
        {
        case 1:
            state = true;
            MenuAddIP();
            break;
        case 2:
            state = true;
            //MenuListIPAll();
            PrintAllIP();
            break;
        case 3:
            state = true;
            MenuListIPSubnet();
            break;
        case 4:
            state = true;
            Conversion();
            break;
        case 5:
            printf("\nThe program will close.\n\n");
            state = true;
            EndProgram();
            break;
        default:
            printf("\nKey no valid. Choose another number : ");
            scanf("%d", &choice);
            state = false;
            break;
        }
    }
}


/**
 * Display Menu to add an IP address into the database
*/
void MenuAddIP(){
    printf("\n\n                       Welcome to Menu Add IP\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$ Add IP Address*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("1 - Add a new IPv4 address\n");
    printf("2 - Previous\n");
    printf("3 - Quit\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n\n");

    int choice;
    printf("Make a choice : ");
    scanf("%d", &choice);

    bool state = false;
    while (!state)
    {
        switch (choice)
        {
        case 1:
            state = true;
            AddIP();
            break;
        case 2:
            state = true;
            printf("\n\n\n");
            Menu();
            break;
        case 3:
            printf("\nThe program will close.\n\n\n");
            state = true;
            EndProgram();
            break;
        default:
            printf("\nKey no valid. Choose another number : ");
            scanf("%d", &choice);
            state = false;
            break;
        }
    } 
}

/**
 * Change value of IPGlobal
*/
void setIP(char ip[16]){
    strcpy(globalIP, ip);
    
}

/**
 * Change value of SubnetMask
*/
void setSubnetMask(char subnetMask[16]){
    strcpy(globalSubnetMask, subnetMask);
}

/**
 * Return IP actual
*/
char* getIP(){
    return globalIP;
}

/**
 * Return SubnetMask actual
*/
char* getSubnetMask(){
    return globalSubnetMask;
}

/**
 * Add IPv4 into the database
*/
void AddIP(){
    char ip[16];
    printf("Enter an IP address : ");
    scanf("%15s", ip);

    char subnetMask[16];
    printf("Enter a subnet mask : ");
    scanf("%15s", subnetMask);

    setIP(ip);
    setSubnetMask(subnetMask);

    if(!ValidationIP(ip, subnetMask)) MenuIPInvalid();
    
    char* actualIP = getIP();
    char* actualSubnetMask = getSubnetMask();
    
    
    
    
    printf("\nAdd the IP address %15s   %s?\n", actualIP, actualSubnetMask);

    printf("1 - Confirm\n");
    printf("2 - Modify\n");
    printf("3 - Previous\n");
    printf("4 - Return the Main Menu\n");
    printf("5 - Quit\n\n");

    int choice;
    printf("Make choice : ");
    scanf("%d", &choice);

    bool state = false;
    while (!state)
    {
        switch (choice)
        {
        case 1:
            FILE *fileIP = fopen(FILENAME, "a");  // Open the file in append mode
            if (fileIP == NULL) {
                perror("**ERROR** Can't open database");
                exit(EXIT_FAILURE);
            }

            char newIP[] = "192.168.1.100";  // Change this IP to the one you want to add
            char newSubnetMask[] = "255.255.255.0";  // Change this subnet mask as needed

            if (!InBDD(actualIP, actualSubnetMask)) {
                fprintf(fileIP, "%s %s\n", actualIP, actualSubnetMask);
                printf("The IP %s %s has been had in the database\n", newIP, newSubnetMask);
            } else {
                printf("The %s already exists in the database.\n", newIP);
            }

            fclose(fileIP);

            printf("Return to the Menu Add IP");
            MenuAddIP();
            state = true;
            break;
        case 2:
            printf("Change the IP address");
            state = true;
            AddIP();
            break;
        case 3:
            printf("The action has been annulled. Return to previous display\n\n");
            MenuAddIP();
            state = true;
            break;
        case 4:
            printf("The action has been annulled. Return to Main Menu\n\n\n");
            Menu();
            state = true;
            break;
        case 5:
            printf("\nThe program will close.\n\n\n");
            state = true;
            EndProgram();
            break;
        default:
            printf("\nKey no valid. Choose another number : ");
            scanf("%d", &choice);
            state = false;
            break;
        }
        
        
    }
    
    
}

/**
 * If format IP address valid return to the main function "Add IP()", else tell where the error is and return to the function "MenuAfterAddIP()"
*/
bool ValidationIP(char ip[16], char subnetMask[16]){
    

    if (IsIPAddressValid(ip) && IsIPMaskValid(subnetMask))
    {
        printf("\nThe IP address format is valid.\n");
        return true;
    }
    else
    {
        printf("**ERROR** The IP address enter isn't valid : \n");
        if(!IsIPAddressValid(ip)) printf("      IP address format invalid.\n");
        if(!IsIPMaskValid(subnetMask)) printf("       IP mask format invalid.\n");
        printf("\n\n");
        return false;
    }
}


/**
 * If IP format invalid -> propose to continue and enter a new IP address or to go back to the previous Menu
*/
void MenuIPInvalid(){
    int choice;
    printf("1 - Enter a new IP address\n");
    printf("2 - Annul Action Ongoing\n");
    printf("Make a choice : ");
    scanf("%d", &choice);

    bool state = false;
    while (!state)
    {
        if (choice == 1)
        {
            char ip[16];
            printf("Enter an IP address : ");
            scanf("%15s", ip);

            char subnetMask[16];
            printf("Enter a subnet mask : ");
            scanf("%15s", subnetMask);

            setIP(ip);
            setSubnetMask(subnetMask);

            if (!ValidationIP(ip, subnetMask))
            {
                MenuIPInvalid();
            }
            
            state = true;
        }
        else if (choice == 2)
        {
            printf("1 - Confirmation annulation\n");
            printf("2 - Continue action\n");

            int choice;
            printf("Make a choice : ");
            scanf("%d", &choice);

            bool state2 = false;
            while (!state2)
            {
                if (choice == 1)
                {
                    printf("Return to Main Menu\n\n\n");
                    Menu();
                    state2 = true;
                }
                else if (choice == 2)
                {
                    state2 = true;
                    MenuIPInvalid();
                }
                else
                {
                    printf("\nKey invalid. Choose another number : ");
                    scanf("%d", &choice);
                }
            }
            
            
            
            state = true;
            //return false;
        }
        else
        {
            printf("\nKey invalid. Choose another number : ");
            scanf("%d", &choice);
            state = false;
        }
    }
    
    
    
}

/**
 * Return true if IP address format is valid, else false
*/
bool IsIPAddressValid(char* ip){
    int a, b, c, d;
    return (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) == 4 && //il vérifie s'il  peut extraire 4 valeurs
            a >= 0 && b <= 255 &&
            b >= 0 && b <= 255 &&
            c >= 0 && c <= 255 &&
            d >= 0 && d <= 255);
}

/**
 * Return true if IP mask format valid, else false
*/
bool IsIPMaskValid(char mask[16]){
    return IsIPAddressValid(mask);
}


/**
 * Display the Menu to list the IP addresses (with a mask) content in the database
*/
void MenuListIPSubnet(){
    printf("\n\n                    Welcome to Menu List IP Subnet\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$ Add IP Address*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("1 - Continue the search\n");
    printf("2 - Main Menu\n");
    printf("3 - Quit\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n");
    printf("*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$\n\n");

    int choice;
    printf("Make a choice : ");
    scanf("%d", &choice);

    bool state = false;
    while (!state)
    {
        if (choice == 1)
        {
            state = true;
            SearchIP();
        }
        else if (choice == 2)
        {
            printf("\nReturn to the Main Menu\n\n\n");
            state = true;
            Menu();
        }
        else if (choice == 3)
        {
            printf("\nThe program will close\n\n\n");
            state = true;
            EndProgram();
        }
        else
        {
           printf("\nKey no valid. Choose another value : ");
           scanf("%d", choice);
           state = false;
        }
    }
}


void etLogique(int adresse_ip[4], int masque[4], int adresse_reseau[4]) {
    for (int i = 0; i < 4; i++) {
        if (adresse_ip[i] == 0 || masque[i] == 0) {   //si l'une de bits est egale a 0 alors le bit du resultat est 0 
            adresse_reseau[i] = 0; 
        } else {
            adresse_reseau[i] = adresse_ip[i]; //sinon il prends la valeur du bit actuel
        }
    }
}

/**
 * Verify if IP is in database
*/
bool InBDD(char ip[16], char subnetMask[16]) {
    FILE *fileIP = fopen(FILENAME, "r");
    if (fileIP == NULL) {
        perror("**ERROR** Can't open database");
        exit(EXIT_FAILURE);
    }

    char IP[16], MASK[16];
    while (fscanf(fileIP, "%s %s", IP, MASK) == 2) {
        if ((strcmp(IP, ip) == 0) && (strcmp(MASK, subnetMask) == 0)) {
            fclose(fileIP);
            return true;  
            //The IP has been found in the database
        }
    }

    fclose(fileIP);
    return false; 
    //The IP hasn't been found in the database
}


/**
 * Print IP in the same subnet and indicate if IP present in the database or not
*/
void printAddresses(int adresseRes[4], char subnetMask[16]) {
    char IPaddress[16];
    
    printf("$*$*$*$*$*$*Printing addresses$*$*$*$*$*$\n");

    for (int i = 0; i <= 255; i++) {
        int address[4];
        //on copie l'adresse reseau dans une nouvelle adresse
        for (int j = 0; j < 4; j++) {
            address[j] = adresseRes[j];
        }
        //on incremente l'adresse reseau 1 par 1
        address[3] += i;

        sprintf(IPaddress, "%d.%d.%d.%d", address[0], address[1], address[2], address[3]);
        
        //on imprime en affichant les quatre parties d'une adresse IP
        strcpy(globalIP, IPaddress);
        strcpy(globalSubnetMask, subnetMask);

        if (InBDD(IPaddress, subnetMask)) {
            printf("Voici une addresse IP de votre réseau qui est stockée dans votre Base de données %s %s\n", globalIP, globalSubnetMask);
        } else {
            printf("Voici une addresse IP de votre réseau mais qui n'est pas dans notre base de donnée : %s %s\n", globalIP, globalSubnetMask);
        }
    }
}


/**
 * Search IP addresses within the same subnet
*/
void SearchIP() {
    char ip[16];
    printf("Enter an IP address : ");
    scanf("%15s", ip);

    char subnetMask[16];
    printf("Enter a subnet mask : ");
    scanf("%15s", subnetMask);

    setIP(ip);
    setSubnetMask(subnetMask);

    if (!ValidationIP(ip, subnetMask)) {
        MenuIPInvalid();
        return; // Exit the function if validation fails
    }

    char *actualIP = getIP();
    char *actualSubnetMask = getSubnetMask();

    int ip_2[4];
    int masque[4];
    int adresse_reseau[4];

    sscanf(actualIP, "%d.%d.%d.%d", &ip_2[0], &ip_2[1], &ip_2[2], &ip_2[3]);
    sscanf(actualSubnetMask, "%d.%d.%d.%d", &masque[0], &masque[1], &masque[2], &masque[3]);

    // Find the network address using the etLogique function
    etLogique(ip_2, masque, adresse_reseau);

    // Print the addresses of the network
    printf("Addresses of the network:\n");
    printAddresses(adresse_reseau, actualSubnetMask);

    printf("\n");
    MenuListIPSubnet();
}


/**
 * Give binary, hexadecimal, and decimal of an IP address
*/
void Conversion(){
    char ip[16];
    printf("Enter an IP address : ");
    scanf("%15s", ip);

    char subnetMask[16];
    printf("Enter a subnet mask : ");
    scanf("%15s", subnetMask);

    setIP(ip);
    setSubnetMask(subnetMask);

    if(!ValidationIP(ip, subnetMask)) MenuIPInvalid();

    char* actualIP = getIP();
    char* actualSubnetMask = getSubnetMask();

    unsigned long decimalIP = (actualIP[0] << 24) | (actualIP[1] << 16) | (actualIP[2] << 8) | actualIP[3];

    printf("Adresse IP en binaire : ");
    for (int j = 31; j >= 0; j--) {
        printf("%lu", (decimalIP >> j) & 1);
        if (j % 8 == 0)
            printf(" ");
    }
    printf("\n");

    printf("Adresse IP en hexadécimal : %X.%X.%X.%X\n", actualIP[0], actualIP[1], actualIP[2], actualIP[3]);

    printf("Adresse IP en décimal : %lu\n", decimalIP);

    printf("\n");

    
    printf("1 - Return the Main Menu\n");
    printf("2 - Quit\n\n");

    int choice;
    printf("Make choice : ");
    scanf("%d", &choice);

    bool state = false;
    while (!state)
    {
        switch (choice)
        {
        case 1:
            printf("Return to Main Menu\n\n\n");
            Menu();
            state = true;
            break;
        case 2:
            printf("\nThe program will close.\n\n\n");
            state = true;
            EndProgram();
            break;
        default:
            printf("\nKey no valid. Choose another number : ");
            scanf("%d", &choice);
            state = false;
            break;
        }
        
        
    }
}

/**
 * Print all the IP in the database
*/
void PrintAllIP() {
    printf("*$*$*$*$*$*$*$*All the IP in the database*$*$*$*$*$*$*$");
    FILE *fileIP = fopen(FILENAME, "r");
    if (fileIP == NULL) {
        perror("**ERROR** Can't open database");
        exit(EXIT_FAILURE);
    }

    char IP[16], subnetMask[16];
    while (fscanf(fileIP, "%s %s", IP, subnetMask) == 2) {
        printf("%s %s\n", IP, subnetMask);
    }

    fclose(fileIP);

    Menu();
}


/**
 * End of the program
*/
void EndProgram(){
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("      ******* #######  ##       ##  ######  *******       \n");
    printf("     *******  ##       ## ##    ##    ##  ##  *******     \n");
    printf("              ##       ##  ##   ##    ##   ##             \n");
    printf("    *******   ####     ##   ##  ##    ##    ## *******    \n");
    printf("              ##       ##    ## ##    ##   ##             \n");
    printf("     *******  ##       ##     ####    ##  ##  *******     \n");
    printf("      ******* ######   ##      ##   ######   *******      \n");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    exit(0);
}


