
string ExtractData (string key, string data) {
    int n = key.size();
    string ret = "";
    for (int i = 0; i < data.size(); i++) {
        if (data.substr(i, n) == key) {
            for (int j = i+1; j < data.size(); j++) {
                ret += data[j];
                if (data[j] == '\n')
                    return ret;
            }
        }
    }
    return ret;
}

string CreateData(vector<string> keys, vector<string> values) {
    string Jtoken;
    for (int i = 0; i < keys.size(); i++) {
        Jtoken += keys[i];
        Jtoken += ":";
        Jtoken += values[i];
        if (i != keys.size() - 1)
            Jtoken += "\n";
    }
    return Jtoken;
}
