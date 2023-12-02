#include "ProgressBarComponent.h"

namespace KanataEngine {

    ProgressBarComponent::ProgressBarComponent(GameObject* go) : BaseComponent(go), progress(0.0f), targetProgress(0.0f), barWidth(0.0f), barSize{ barSize.x, barSize.y }, initialPosition{ initialPosition.x, initialPosition.y }
    {
    }

    ProgressBarComponent::~ProgressBarComponent()
    {
    }

    void ProgressBarComponent::setInitialPosition(Vec2 pos)
    {
        initialPosition = { pos.x, pos.y };
    }

    void ProgressBarComponent::setProgress(float value)
    {
        progress = value;
    }

    void ProgressBarComponent::setTargetProgress(float value)
    {
        targetProgress = value;
    }

    void ProgressBarComponent::setBarWidth(float width)
    {
        barWidth = width;
    }

    void ProgressBarComponent::setSize(Vec2 valSize)
    {
        barSize = { valSize.x, valSize.y };
    }

    void ProgressBarComponent::awake()
    {
    }

    void ProgressBarComponent::start()
    {
        targetProgress = 1.0f;
    }

    void ProgressBarComponent::update(float deltaTime)
    {
        progress += deltaTime * 0.5f;
        progress = std::min(progress, targetProgress);

        barWidth = barSize.x * (progress / targetProgress);
    }

    void ProgressBarComponent::render()
    {

        glPushMatrix();
        glTranslatef(initialPosition.x, initialPosition.y, 0);

        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_QUADS);
        glVertex3f(0, 0, 0);
        glVertex3f(barSize.x, 0, 0);
        glVertex3f(barSize.x, barSize.y, 0);
        glVertex3f(0, barSize.y, 0);
        glEnd();

        // Draw the progress bar (scaled width)
        glColor3f(0.0f, 0.8f, 0.0f); // Green color
        glBegin(GL_QUADS);
        glVertex3f(0, 0, 0);
        glVertex3f(barWidth, 0, 0);
        glVertex3f(barWidth, barSize.y, 0);
        glVertex3f(0, barSize.y, 0);

        glEnd();

        glPopMatrix();
    }

}

