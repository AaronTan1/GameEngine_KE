#include "SplashScene.h"

namespace SplashArtScene {

	std::string SplashScene::getName() const
	{
		return "SplashScene";
	}

	void SplashScene::skipScene()
	{
		SceneStateMachine::loadScene(1);
	}

	void SplashScene::loadGameObj()
	{
		GameObject* goSA = new GameObject("splashArt");
		goSA->addComponent<SpriteRendererComponent>(0.0f, 0.0f, sprites[0]);
		spriteRendererComponent[0] = goSA->getComponent<SpriteRendererComponent>();
		spriteRendererComponent[0]->setSize({ 1000.0f, 600.0f });

		GameObject* goDet = new GameObject("detailsObj");
		goDet->addComponent<SpriteRendererComponent>(-200.0f, -150.0f, sprites[1]);
		spriteRendererComponent[1] = goDet->getComponent<SpriteRendererComponent>();
		spriteRendererComponent[1]->setSize({ 400.0f, 40.0f });

	}

	void SplashScene::initialize()
	{
		loadGameObj();

		GameObject* goTitle = new GameObject("titleObj");
		goTitle->addComponent<SpriteRendererComponent>(-200.0f, 40.0f, sprites[2]);
		spriteRendererComponent[2] = goTitle->getComponent<SpriteRendererComponent>();
		spriteRendererComponent[2]->setSize({ 400.0f, 110.0f });

		GameObject* go = new GameObject("test_in_splash_gameobject");
		go->addComponent<Test_Foo_Component>();

	}


	void SplashScene::on_activate()
	{
		glClearColor(0.25, 0, 0, 1);

		time = 0.0f;
	}

	void SplashScene::on_update(float deltaTime)
	{
		time += deltaTime;

		if (time > 5.0f)
		{
			SceneStateMachine::loadScene(1);
		}

		if (inputSystem.getKeyDown(GLFW_KEY_SPACE) && SceneStateMachine::sceneIndex == 0)
		{
			std::cout << "SPLASH SCENE SKIPPED!" << std::endl;
			skipScene();
		}



	}

	void SplashScene::on_render()
	{
		//glPushMatrix();

		//glTranslatef(0, 0, 0);

		//glBegin(GL_TRIANGLES);
		//glColor3f(1, 0, 0);
		//glVertex3f(0, 150, 0);
		//glColor3f(0, 1, 0);
		//glVertex3f(-150, -150, 0);
		//glColor3f(0, 0, 1);
		//glVertex3f(150, -150, 0);

		//glEnd();

		//glPopMatrix();
	}

}


