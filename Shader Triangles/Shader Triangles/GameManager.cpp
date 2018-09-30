#include "GameManager.h"


GameManager * GameManager::instance = NULL;

GameManager * GameManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new GameManager();
	}
	return instance;
}

void GameManager::updatePVM(GameObject * gameObject)
{
	gameObject->calculatePVMMatrix(camera->GetPV());
}

void GameManager::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); //clear red

	switch (GetInstance()->currentGameState)
	{
	case menuScreen:
	{
		GetInstance()->menuImage->render(GetInstance()->program);
		GetInstance()->gameMenu->render(GetInstance()->program);
		break;
	}
	case introSequence:
	{
		GetInstance()->introScene->render(GetInstance()->program);
		break;
	}
	case zombieRoom:
	{
		GetInstance()->background->render(GetInstance()->program);
		GetInstance()->player->render(GetInstance()->program);
		GetInstance()->zombie->render(GetInstance()->program);
		GetInstance()->text->render();
		break;
	}
	case zombieCutscene:
	{
		GetInstance()->zombieScene->render(GetInstance()->program);
		break;
	}
	case ratRoom:
	{
		GetInstance()->background->render(GetInstance()->program);
		GetInstance()->player->render(GetInstance()->program);
		GetInstance()->rat->render(GetInstance()->program);
		GetInstance()->text->render();
		break;
	}
	case ratCutscene:
	{
		GetInstance()->ratScene->render(GetInstance()->program);
		break;
	}
	case batRoom:
	{
		GetInstance()->background->render(GetInstance()->program);
		GetInstance()->player->render(GetInstance()->program);
		GetInstance()->batKnight->render(GetInstance()->program);
		GetInstance()->text->render();
		break;
	}
	case batCutscene:
	{
		GetInstance()->batScene->render(GetInstance()->program);
		break;
	}
	case multiRoom:
	{
		GetInstance()->background->render(GetInstance()->program);
		GetInstance()->player->render(GetInstance()->program);
		GetInstance()->batKnight->render(GetInstance()->program);
		GetInstance()->zombie->render(GetInstance()->program);
		GetInstance()->rat->render(GetInstance()->program);
		GetInstance()->text->render();
		break;
	}
	case finalCutScene:
	{
		GetInstance()->finalScene->render(GetInstance()->program);
		break;
	}
	case pauseScreen:
	{
		break;
	}
	case gameOverScreen:
	{
		break;
	}
	default:
	{
		break;
	}
	}

	glUseProgram(0); //Unbind Program

	glutSwapBuffers();
}

void GameManager::init()
{
	//ShaderLoader shaderLoader; 
	program = ShaderLoader::getInstance()->CreateProgram("VertexShader.vs", "FragmentShader.fs");

	Clock::GetInstance()->Initialise();
	gameMenu->initialise();
	player->initialise();
	batKnight->initialise();
	vectorOfGameObjects.push_back(batKnight);
	zombie->initialise();
	vectorOfGameObjects.push_back(zombie);
	rat->initialise();
	vectorOfGameObjects.push_back(rat);
	introScene->initialise();
	ratScene->initialise();
	batScene->initialise();
	zombieScene->initialise();
	finalScene->initialise();
	menuImage->initialise();
	text->initialise();

	background->initialise();
	camera->Initialise();
}

void GameManager::Update()
{
	Clock::GetInstance()->Update();
	GetInstance()->deltaTime = Clock::GetInstance()->GetDeltaTick();
	GetInstance()->camera->Update(GetInstance()->deltaTime);
	GetInstance()->updatePVM(GetInstance()->player);

	switch (GetInstance()->currentGameState)
	{
	case menuScreen:
	{
		GetInstance()->menuImage->update(GetInstance()->deltaTime);
		GetInstance()->updatePVM(GetInstance()->menuImage);
		GetInstance()->gameMenu->update(GetInstance()->deltaTime);
		if (GetInstance()->gameMenu->getFirstClicked() == true)
		{
			GetInstance()->currentGameState = introSequence;
		}
		if (GetInstance()->gameMenu->getSecondClicked() == true)
		{
			glutLeaveMainLoop();
		}
		break;
	}
	case introSequence:
	{
		GetInstance()->introScene->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->introScene);
		if (GetInstance()->introScene->getIsVisible() == false)
		{
			GetInstance()->currentGameState = zombieRoom;
		}
		break;
	}
	case zombieRoom:
	{
		GetInstance()->background->update(GetInstance()->deltaTime);
		GetInstance()->updatePVM(GetInstance()->background);
		GetInstance()->player->update(GetInstance()->deltaTime, GetInstance()->program, GetInstance()->vectorOfGameObjects);
		GetInstance()->updatePVM(GetInstance()->player);
		GetInstance()->zombie->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->zombie);

		if (GetInstance()->zombie->getIsVisible() == false)
		{
			GetInstance()->currentGameState = zombieCutscene;
		}

		break;
	}
	case zombieCutscene:
	{	
		GetInstance()->zombieScene->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->zombieScene);
		if (GetInstance()->zombieScene->getIsVisible() == false)
		{
			GetInstance()->currentGameState = ratRoom;
		}
		break;
	}
	case ratRoom:
	{
		GetInstance()->background->update(GetInstance()->deltaTime);
		GetInstance()->updatePVM(GetInstance()->background);
		GetInstance()->player->update(GetInstance()->deltaTime, GetInstance()->program, GetInstance()->vectorOfGameObjects);
		GetInstance()->updatePVM(GetInstance()->player);
		GetInstance()->rat->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->rat);

		if (GetInstance()->rat->getIsVisible() == false)
		{
			GetInstance()->currentGameState = ratCutscene;
		}
		break;
	}
	case ratCutscene:
	{
		GetInstance()->ratScene->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->ratScene);
		if (GetInstance()->ratScene->getIsVisible() == false)
		{
			GetInstance()->currentGameState = batRoom;
		}
		break;
	}
	case batRoom:
	{
		GetInstance()->background->update(GetInstance()->deltaTime);
		GetInstance()->updatePVM(GetInstance()->background);
		GetInstance()->player->update(GetInstance()->deltaTime, GetInstance()->program, GetInstance()->vectorOfGameObjects);
		GetInstance()->updatePVM(GetInstance()->player);
		GetInstance()->batKnight->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->batKnight);
		if (GetInstance()->batKnight->getIsVisible() == false)
		{
			GetInstance()->currentGameState = batCutscene;
		}
		break;
	}
	case batCutscene:
	{
		GetInstance()->batScene->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->batScene);
		if (GetInstance()->batScene->getIsVisible() == false)
		{
			GetInstance()->currentGameState = multiRoom;
		}
		break;
	}
	case multiRoom:
	{
		if (GetInstance()->lifeReset == 1)
		{
			GetInstance()->zombie->setIsVisible(true);
			GetInstance()->rat->setIsVisible(true);
			GetInstance()->batKnight->setIsVisible(true);
			GetInstance()->lifeReset++;
		}
		GetInstance()->background->update(GetInstance()->deltaTime);
		GetInstance()->updatePVM(GetInstance()->background);
		GetInstance()->player->update(GetInstance()->deltaTime, GetInstance()->program, GetInstance()->vectorOfGameObjects);
		GetInstance()->updatePVM(GetInstance()->player);
		GetInstance()->zombie->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->zombie);
		GetInstance()->rat->update(GetInstance()->deltaTime, GetInstance()->program); 
		GetInstance()->updatePVM(GetInstance()->rat);
		GetInstance()->batKnight->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->batKnight);
		if (GetInstance()->batKnight->getIsVisible() == false && GetInstance()->rat->getIsVisible() == false && GetInstance()->zombie->getIsVisible() == false)
		{
			GetInstance()->currentGameState = finalCutScene;
		}
		break;
	}
	case finalCutScene:
	{
		GetInstance()->finalScene->update(GetInstance()->deltaTime, GetInstance()->program);
		GetInstance()->updatePVM(GetInstance()->finalScene);
		if (GetInstance()->finalScene->getIsVisible() == false)
		{
			glutLeaveMainLoop();
		}
		break;
	}
	case pauseScreen:
	{
		break;
	}
	case gameOverScreen:
	{
		break;
	}
	default:
	{
		break;
	}
	}

	glutPostRedisplay();
}

void GameManager::playGame(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500); glutInitWindowSize(800, 600);
	glutCreateWindow("Tom's OpenGL Assignment 2");
	glClearColor(1.0, 0.0, 0.0, 1.0);//clear red
									 // register callbacks

	glewInit();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GetInstance()->init();

	glutDisplayFunc(GameManager::render);
	glutIdleFunc(GameManager::Update);

	glutKeyboardFunc(Input::KeyboardDown);
	glutKeyboardUpFunc(Input::KeyboardUp);
	glutMouseFunc(Input::mouseClick);
	glutMotionFunc(Input::mouseMove);
	glutPassiveMotionFunc(Input::mousePassiveMove);
	glutMainLoop();
}

GameManager::GameManager()
{
	//Game Menu
	gameMenu = new GameMenu("Start Quest (Press S)", "Be an Elf (Press Q)");
	//Camera
	camera = new Camera();
	//IntroScene
	introScene = new IntroScene();
	//Player
	player = new Player();
	//Bat Enemy
	batKnight = new BatKnight();
	//Zombie Enemy
	zombie = new Zombie();
	//Rat Enemy
	rat = new Rat();
	//Text Label
	text = new TextLabel("Enimies Remaining:", "Dependencies/Fonts/SnackerComic.ttf", glm::vec2(-390.0f, 350.0f));
	//Background
	background = new Background();
	//MenuImage
	menuImage = new MenuImage();
	//GameObject
	gameObject = new GameObject();
	float deltaTime = 0.0f;

	//Scenes
	introScene = new IntroScene();
	batScene = new BatScene();
	ratScene = new RatScene();
	zombieScene = new ZombieScene();
	finalScene = new FinalScene();

}

GameManager::~GameManager()
{
}
