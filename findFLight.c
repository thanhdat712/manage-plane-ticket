NodeFlight* findFlight(char* id) {
    NodeFlight* p = headFlight;
    while (p) { 
        if (strcmp(p->data.ID, id) == 0) 
            return p; 
        p = p->next; 
    }
    return NULL;
}
