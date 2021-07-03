#include<string>

/*
string ExtractJson(string Jtoken, string Class) {
    string ret
    int token_index = 0, index = 0;
    while (token_index < strlen(Jtoken)) {
        if (strcmp(substr(Jtoken, token_index, token_index + (int)strlen(Class)), Class) == 0) {
            token_index += (int)strlen(Class);
            break;
        }
        token_index++;
    }
    token_index++;
    while (Jtoken[token_index] != '\"') token_index++;
    token_index++;
    while (Jtoken[token_index] != '\"') ret[index++] = Jtoken[token_index++];
    return ret;
}*/

string CreatePersonData(vector<string> keys, vector<string> values) {
    string Jtoken;
    for (int i = 0; i < keys.size(); i++) {
        Jtoken += keys[i];
        Jtoken += " : ";
        Jtoken += values[i];
        if (i != keys.size() - 1)
            Jtoken += "\n";
    }
    return Jtoken;
}
