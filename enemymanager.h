#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include "Enemy.h"

class EnemyManager
{
private:
   EnemyManager() {}
   EnemyManager(const EnemyManager&) {
       return *this;
   }
//   EnemyManager& (const EnemyManager&) {
//       return *this;
//   }

public:

   static EnemyManager & instance() {
       static EnemyManager * _instance = 0;
       if ( _instance == 0 ) {
           _instance = new EnemyManager();
       }
       return *_instance;
   }
   void preSetEnemies();
   void getOrCreateEnemy();
   void createEnemy();
public slots:
   void spawn();
private:
   QVector <Enemy> enemies;
};


#endif // ENEMYMANAGER_H
