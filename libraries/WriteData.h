string ExtractData (string key, string data) {
    int n = data.size();
    string ret = "";
    int i = 0;
    string KEY = "";
    for (; i < n; i++) {
        if (data[i] == ':' && KEY == key) {
            i++;
            break;
        }
        else if (data[i] == ':' && KEY != key) {
            KEY = "";
            int index = i+1;
            while (data[index] != '#' && i < n)
                index++;
            i = index + 1;
        }
        KEY += data[i];
    }
    for (; i < n; i++) {
        if (data[i] == '#')
            return ret;
        ret += data[i];
    }
    return "";
}

string CreateData(vector<string> keys, vector<string> values) {
    string Jtoken;
    for (int i = 0; i < keys.size(); i++) {
        Jtoken += keys[i];
        Jtoken += ":";
        Jtoken += values[i];
        if (i != keys.size() - 1)
            Jtoken += '#';
    }
    Jtoken += '#';
    return Jtoken;
}
