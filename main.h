#define __MAIN_HEAD__ "main.h"
#define True 1
#define False 0

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

/*Head File*/

#include"Head\Model\Player\player.h"
#include"Head\Model\Game\gameReferee.h"
#include"Head\Model\Game\gameMode.h"
#include"Head\Model\Game\fileIO.h"

#include"Head\View\gameModeView.h"
#include"Head\View\view.h"

#include"Head\Controller\gameModeController.h"
#include"Head\Controller\controller.h"

/*C File*/

#include"Model\Player\player.c"
#include"Model\Game\gameReferee.c"
#include"Model\Game\gameMode.c"
#include"Model\Game\fileIO.c"

#include"View\gameModeView.c"
#include"View\view.c"

#include"Controller\gameModeController.c"
#include"Controller\controller.c"