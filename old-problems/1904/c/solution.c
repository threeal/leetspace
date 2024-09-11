int numberOfRounds(char* loginTime, char* logoutTime) {
  int login = ((loginTime[0] - '0') * 10 + loginTime[1] - '0') * 60 +
      (loginTime[3] - '0') * 10 + loginTime[4] - '0';

  int logout = ((logoutTime[0] - '0') * 10 + logoutTime[1] - '0') * 60 +
      (logoutTime[3] - '0') * 10 + logoutTime[4] - '0';

  if (logout < login) logout += 24 * 60;
  if (login % 15 > 0) login += 15;

  const int rounds = logout / 15 - login / 15;
  return rounds > 0 ? rounds : 0;
}
