# Deadlock
This project demonstrates deadlocks in an operating system along with prevention and avoidance of deadlock.

# To Run:

## Clone the repository
```bash
git clone https://github.com/Padmashree06/Deadlock.git
```

```bash
cd Deadlock
```

## For deadlock simulation
```bash
g++ deadlock_simulation.cpp -o deadlock_simulation -pthread
```

```bash
./deadlock_simulation
```

## For deadlock prevention
```bash
g++ deadlock_prevention.cpp -o deadlock_prevention -pthread
```
```bash
./deadlock_prevention
```

## For deadlock avoidance
```bash
g++ deadlock_avoidance.cpp -o deadlock_avoidance -pthread
```
```bash
./deadlock_avoidance
```