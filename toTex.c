how to hash a string:

hash map:

int hash = 0;
for(int i = 0; str[i] != '\0'; i++) hash = ((hash << 1) + str[i])
