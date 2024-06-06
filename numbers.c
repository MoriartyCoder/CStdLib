extern int countDigits(long long llNumber) {
  int iCount = 0;

  // Berücksichtige negative Zahlen
  if (llNumber == 0) {
    return 1;
  }

  if (llNumber < 0) {
    llNumber = -llNumber;
  }

  // Zähle die Anzahl der Stellen
  while (llNumber != 0) {
    llNumber /= 10;
    iCount++;
  }

  return iCount;
}
