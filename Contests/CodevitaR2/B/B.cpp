#include <bits/stdc++.h>
using namespace std;

typedef long long sizet;

struct rank_part {
  sizet id;
  sizet score;
  double partial;

  bool operator<(const rank_part &rhs) const {
    if (score == rhs.score && partial == rhs.partial) {
      return id < rhs.id;
    } else if (score == rhs.score) {
      return partial > rhs.partial;
    } else {
      return score > rhs.score;
    }
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sizet problems;
  cin >> problems;
  map<string, pair<sizet, sizet>> problem;
  map<string, sizet> problems_ids;
  for (sizet i = 0; i < problems; ++i) {
    string id;
    sizet score;
    sizet tests;
    cin >> id >> score >> tests;
    //  cout << id << " " << score << " " << tests << endl;
    problem[id] = {score, tests};
    problems_ids[id] = i;
  }

  sizet contestans, submissions;
  cin >> contestans >> submissions;
  //  cout << "calculating scores" << endl;
  map<sizet, vector<pair<double, bool>>> participant;
  for (sizet i = 0; i < submissions; ++i) {
    sizet contestant_id, submission_id;
    string problem_id;
    cin >> contestant_id >> problem_id >> submission_id;
    if (participant.find(contestant_id) == participant.end()) {
      participant[contestant_id] = vector<pair<double, bool>>(problems);
    }
    string answer;
    bool fullscore = 1;
    double score = 0;
    //  cout << "calculating score for problem" << problem_id << endl;
    for (sizet j = 0; j < problem[problem_id].second; ++j) {
      cin >> answer;
      if (answer != "A") {
        fullscore = 0;
      } else {
        score += (double)problem[problem_id].first / problem[problem_id].second;
      }
    }
    // cout << "updating participant " << contestant_id << " score in problem "
    //      << problem_id << endl;
    // cout << participant[contestant_id].size() << endl;
    if (participant[contestant_id][problems_ids[problem_id]].first < score) {
      // cout << "updating score" << endl;
      participant[contestant_id][problems_ids[problem_id]] = {score, fullscore};
    }
  }
  set<rank_part> ranking;
  vector<rank_part> ranks;
  for (auto &elems : participant) {
    sizet score = 0;
    double partial = 0;
    for (auto &par : elems.second) {
      if (par.second) {
        score += (sizet)round(par.first);
      } else {
        partial += par.first;
      }
    }
    if (score > 0 || partial > 0) {
      ranking.insert({elems.first, score, partial});
    }
  }
  for (auto &elem : ranking) {
    ranks.push_back(elem);
  }
  sizet pos = 1;
  sizet same_rank = 0;
  for (size_t i = 0; i < ranks.size(); ++i) {
    if (i > 0) {
      if (ranks[i].score == ranks[i - 1].score &&
          ranks[i].partial == ranks[i - 1].partial) {
        pos--;
        same_rank++;
      } else {
        pos += same_rank;
        same_rank = 0;
      }
    }
    printf("%lld %lld %lld %.2f\n", pos, ranks[i].id, ranks[i].score,
           ranks[i].partial);
    pos++;
  }
}
