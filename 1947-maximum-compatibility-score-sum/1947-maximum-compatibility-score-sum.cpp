class Solution {
public:
    int getScore(vector<int>& student, vector<int>& mentor) {
        int score = 0;
        for (int i = 0; i < student.size(); ++i) {
            if (student[i] == mentor[i]) ++score;
        }
        return score;
    }

    int search(int studentIndex, vector<vector<int>>& students,vector<vector<int>>& mentors,vector<bool>& mentorUsed) {
        // All students have been assigned.
        if (studentIndex == students.size()) return 0;

        int best = 0;

        // Try each mentor for this student.
        for (int j = 0; j < mentors.size(); ++j) {
            if (!mentorUsed[j]) {
                mentorUsed[j] = true;

                int total = getScore(students[studentIndex], mentors[j])
                          + search(studentIndex + 1, students, mentors, mentorUsed);

                best = max(best, total);
                mentorUsed[j] = false; // Undo choice for the next try.
            }
        }

        return best;
    }

    int maxCompatibilitySum(vector<vector<int>>& students,
                            vector<vector<int>>& mentors) {
        vector<bool> mentorUsed(mentors.size(), false);
        return search(0, students, mentors, mentorUsed);
    }
};