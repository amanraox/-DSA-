class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while (i < version1.size() || j < version2.size()) {
            int revision1 = getRevision(version1, i);
            int revision2 = getRevision(version2, j);
            if (revision1 > revision2) {
                return 1;
            } else if (revision2 > revision1) {
                return -1;
            }
        }
        return 0;
    }

    int getRevision(const string &version, int &i) {
        int revision = 0;
        while (i < version.size() && version[i] != '.') {
            revision = revision * 10 + (version[i] - '0');
            ++i;
        }
        ++i;
        return revision;
    }
};