
int dice_match(char *string1, char *string2)
        {
        struct pairs
                {
                char chars[2];
                struct pairs *next;
                };
        struct pairs *string1head = NULL;
        struct pairs *string1current;
        struct pairs *string1previous;
        struct pairs *string2head = NULL;
        struct pairs *string2current;
        struct pairs *string2previous;
        
        int counter=0, string1pairs=0, string2pairs=0;
        
        if (string1[0]=='\0' || string2[0]=='\0')
                return 0;
        while (string1[counter+1] != '\0')
                {
                if (string1[counter] != ' ' && string1[counter+1] != ' ')
                        {
                        string1current = (struct pairs *) malloc(sizeof(struct pairs));
                        if (string1current==NULL)
                                exit(EXIT_FAILURE);
                        if (string1head == NULL)      
                                string1head = string1current;
                        else                   
                                string1previous->next = string1current;
                        string1current->next = NULL;
                        string1current->chars[0]=toupper(string1[counter]);
                        string1current->chars[1]=toupper(string1[counter+1]);
                        string1previous=string1current;
                        string1pairs++;
                        }
                counter++;
                }
                
        counter=0;      
        while (string2[counter+1] != '\0')
                {
                if (string2[counter] != ' ' && string2[counter+1] != ' ')
                        {
                        string2current = (struct pairs *) malloc(sizeof(struct pairs));
                        if (string2current==NULL)
                                exit(EXIT_FAILURE);
                        if (string2head == NULL)      
                                string2head = string2current;
                        else                   
                                string2previous->next = string2current;
                        string2current->next = NULL;
                        string2current->chars[0]=toupper(string2[counter]);
                        string2current->chars[1]=toupper(string2[counter+1]);
                        string2previous=string2current;
                        string2pairs++;
                        }
                counter++;
                }
        counter=0;
        string1current=string1head;
        while (string1current != NULL)
                {
                string2current=string2head;
                while (string2current != NULL)
                        {
                        if (string2current->chars[0]== string1current->chars[0] && string2current->chars[1]==string1current->chars[1])
                                {
                                string2current->chars[0]='\0'; // Otherwise, 'GGGGG' would score a perfect match against 'GG'.
                                counter+=2;
                                break;
                                }
                        string2current=string2current->next;
                        }
                string1current=string1current->next;
                }
                
    string1current = string1head;
    while (string1current != NULL)
        {
        free(string1current);
        string1current = string1current->next;
        }
    string2current = string2head;
    while (string2current != NULL)
        {
        free(string2current);
        string2current = string2current->next;
        }
    return (((double)counter/(string1pairs+string2pairs))*100);
    }
