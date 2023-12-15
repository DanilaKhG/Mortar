#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// Функция для определения расстояния между двумя точками
float distance_func(sf::Vector2f v1, sf::Vector2f v2) {
    return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080),  "mortar");
    sf::Texture phonTexture;
    if (!phonTexture.loadFromFile("phon.jpg")) {
        std::cerr << "Failed to load phon texture" << std::endl;
        return 1;
    }
    sf::Sprite phonSprite(phonTexture);
    phonSprite.setPosition(0, 0);
    sf::Font font;
    if (!font.loadFromFile("arialmt.ttf"))
    {
        std::cerr << "Failed to load arial font" << std::endl;
        return 1;
    }
    
    // Создание спрайтов для миномёта, танков, снаряда и сердец
    sf::Texture cannonTexture;
    if(!cannonTexture.loadFromFile("cannon.png")) {
        std::cerr << "Failed to load cannon texture" << std::endl;
        return 1;
    }
    sf::Sprite cannonSprite(cannonTexture);
    cannonSprite.setPosition(50, 700);
    sf::Texture tankTexture;
    if (!tankTexture.loadFromFile("tank.png")) {
        std::cerr << "Failed to load tank texture" << std::endl;
        return 1;
    }
    sf::Texture bombtankTexture;
    if (!bombtankTexture.loadFromFile("bombtank2.png")) {
        std::cerr << "Failed to load bombtank texture" << std::endl;
        return 1;
    }
    sf::Texture ballTexture;
    if (!ballTexture.loadFromFile("ball.png")) {
        std::cerr << "Failed to load ball texture" << std::endl;
        return 1;
    }
    sf::Sprite ballSprite(ballTexture);
    ballSprite.setPosition(2000, 2000);
    sf::Texture shellTexture;
    if (!shellTexture.loadFromFile("shell.png")) {
        std::cerr << "Failed to load shell texture" << std::endl;
        return 1;
    }
    sf::Sprite shellSprite(shellTexture);
    shellSprite.setPosition(10, 10);

    sf::Texture heart2Texture;
    if (!heart2Texture.loadFromFile("heart2.png")) {
        std::cerr << "Failed to load heart2 texture" << std::endl;
        return 1;
    }
    sf::Texture heart1Texture;
    if (!heart1Texture.loadFromFile("heart1.png")) {
        std::cerr << "Failed to load heart1 texture" << std::endl;
        return 1;
    }
    sf::Texture heart0Texture;
    if (!heart0Texture.loadFromFile("heart0.png")) {
        std::cerr << "Failed to load heart0 texture" << std::endl;
        return 1;
    }

    sf::Texture one1Texture;
    if (!one1Texture.loadFromFile("1.png")) {
        std::cerr << "Failed to load 1.png texture" << std::endl;
        return 1;
    }
    sf::Texture one2Texture;
    if (!one2Texture.loadFromFile("2.png")) {
        std::cerr << "Failed to load 2.png texture" << std::endl;
        return 1;
    }
    sf::Texture one3Texture;
    if (!one3Texture.loadFromFile("3.png")) {
        std::cerr << "Failed to load 3.png texture" << std::endl;
        return 1;
    }
    sf::Texture one4Texture;
    if (!one4Texture.loadFromFile("4.png")) {
        std::cerr << "Failed to load 4.png texture" << std::endl;
        return 1;
    }
    sf::Texture one5Texture;
    if (!one5Texture.loadFromFile("5.png")) {
        std::cerr << "Failed to load 5.png texture" << std::endl;
        return 1;
    }
    sf::Sprite one1Sprite(one1Texture);
    one1Sprite.setPosition(200, 800);

    sf::Texture two1Texture;
    if (!two1Texture.loadFromFile("6.png")) {
        std::cerr << "Failed to load 6.png texture" << std::endl;
        return 1;
    }
    sf::Texture two2Texture;
    if (!two2Texture.loadFromFile("7.png")) {
        std::cerr << "Failed to load 7.png texture" << std::endl;
        return 1;
    }
    sf::Texture two3Texture;
    if (!two3Texture.loadFromFile("8.png")) {
        std::cerr << "Failed to load 8.png texture" << std::endl;
        return 1;
    }
    sf::Texture two4Texture;
    if (!two4Texture.loadFromFile("9.png")) {
        std::cerr << "Failed to load 9.png texture" << std::endl;
        return 1;
    }
    sf::Texture two5Texture;
    if (!two5Texture.loadFromFile("10.png")) {
        std::cerr << "Failed to load 10.png texture" << std::endl;
        return 1;
    }
    sf::Sprite two1Sprite(two1Texture);
    two1Sprite.setPosition(50, 600);
    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(50);
    text2.setString("You are ready?");
    text2.setPosition(2000, 2000);
    sf::Text text3;
    text3.setFont(font);
    text3.setCharacterSize(30);
    text3.setString("Press R");
    text3.setPosition(2000, 2000);
    

    int remainingShells = 15;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString(std::to_string(remainingShells));
    text.setPosition(100, 32);
    text.setFillColor(sf::Color::Black);
    text2.setFillColor(sf::Color::Black);
    text3.setFillColor(sf::Color::Black);
    int tank1Health = 2;
    int tank2Health = 2;
    int tank3Health = 2;
    bool isShooting = false;
    float angle = 20.0f;
    float power = 80.0f;
    sf::Vector2f projectilePosition;
    sf::Vector2f projectileVelocity;
    bool isGameOver = false;
    bool result = false;
    bool isEnd = false;
    const float gravity = 9.81f;
    const float timeStep = 0.01f;
    sf::Vector2f cannonPosition = sf::Vector2f(170.0f, 760.0f);
    sf::Vector2f tank1Position = sf::Vector2f(1500.0f, 650.0f);
    sf::Vector2f tank2Position = sf::Vector2f(1200.0f, 700.0f);
    sf::Vector2f tank3Position = sf::Vector2f(950.0f, 850.0f);

    sf::Sprite tank1Sprite(tankTexture);
    tank1Sprite.setPosition(tank1Position);
    sf::Sprite tank2Sprite(tankTexture);
    tank2Sprite.setPosition(tank2Position);
    sf::Sprite tank3Sprite(tankTexture);
    tank3Sprite.setPosition(tank3Position);

    sf::Sprite heart1Sprite(heart2Texture);
    sf::Sprite heart2Sprite(heart2Texture);
    sf::Sprite heart3Sprite(heart2Texture);
    heart1Sprite.setPosition(tank1Position.x + 100, tank1Position.y - 20);
    heart2Sprite.setPosition(tank2Position.x + 100, tank2Position.y - 20);
    heart3Sprite.setPosition(tank3Position.x + 100, tank3Position.y - 20);

    sf::Texture GameOverTexture;
    if (!GameOverTexture.loadFromFile("GameOver.png")) {
        std::cerr << "Failed to load GameOver texture" << std::endl;
        return 1;
    }
    sf::Sprite GameOverSprite(GameOverTexture);
    GameOverSprite.setPosition(2000, 2000);
    sf::Texture YouWinTexture;
    if (!YouWinTexture.loadFromFile("youwin.png")) {
        std::cerr << "Failed to load GameOver texture" << std::endl;
        return 1;
    }
    while (window.isOpen())
    {
        sf::Event event;
        if (isGameOver) {
            if (tank1Health > 0) {
                sf::Vector2f direction = cannonPosition - tank1Position;
                sf::Vector2f direction2 = tank2Position - tank1Position;
                sf::Vector2f direction3 = tank3Position - tank1Position;
                sf::Vector2f direction4 = tank3Position - tank2Position;
                float length = distance_func(cannonPosition, tank1Position);
                float length2 = distance_func(tank2Position, tank1Position);
                float length3 = distance_func(tank3Position, tank1Position);
                float length4 = distance_func(tank3Position, tank2Position);
                direction /= length;
                if (length2 < 100)
                    tank1Position.y -= 0.25f;
                else if (length3 < 100)
                    tank1Position.y -= 0.25f;
                else tank1Position += direction * timeStep;
                tank1Sprite.setPosition(tank1Position);
                heart1Sprite.setPosition(tank1Position.x + 100, tank1Position.y - 20);
                if (distance_func(tank1Position, cannonPosition) < 50.0f) {
                    isGameOver = false;
                    isEnd = true;
                }
            }
            if (tank2Health > 0) {
                sf::Vector2f direction = cannonPosition - tank2Position;
                sf::Vector2f direction2 = tank3Position - tank2Position;
                float length = distance_func(cannonPosition, tank2Position);
                float length2 = distance_func(tank3Position, tank2Position);
                direction /= length;
                if (length2 < 100) {
                    tank2Position.x += 0.4f;
                    tank2Position.y += 0.25f;
                }
                tank2Position += direction * timeStep;
                tank2Sprite.setPosition(tank2Position);
                heart2Sprite.setPosition(tank2Position.x + 100, tank2Position.y - 20);
                if (distance_func(tank2Position, cannonPosition) < 50.0f) {
                    isGameOver = false;
                    isEnd = true;
                }
            }
            if (tank3Health > 0) {
                sf::Vector2f direction = cannonPosition - tank3Position;
                float length = sqrt(direction.x * direction.x + direction.y * direction.y);
                direction /= length;
                tank3Position += direction * timeStep;
                tank3Sprite.setPosition(tank3Position);
                heart3Sprite.setPosition(tank3Position.x + 100, tank3Position.y - 20);
                if (distance_func(tank3Position, cannonPosition) < 50.0f) {
                    isGameOver = false;
                    isEnd = true;
                }
            }
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (isGameOver) {
                    if (event.key.code == sf::Keyboard::Right) {
                        power += 5.0f;
                        if (power > 145)
                            power = 145;
                    }
                    else if (event.key.code == sf::Keyboard::Left) {
                        power -= 5.0f;
                        if (power < 85)
                            power = 85;
                    }
                    else if (event.key.code == sf::Keyboard::Up) {
                        angle += 5.0f;
                        if (angle > 65)
                            angle = 65;
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        angle -= 5.0f;
                        if (angle < 20)
                            angle = 20;
                    }
                    if (power == 95)
                        one1Sprite.setTexture(one2Texture);
                    if (power == 110)
                        one1Sprite.setTexture(one3Texture);
                    if (power == 125)
                        one1Sprite.setTexture(one4Texture);
                    if (power == 140)
                        one1Sprite.setTexture(one5Texture);
                    if (angle == 30)
                        two1Sprite.setTexture(two2Texture);
                    if (angle == 40)
                        two1Sprite.setTexture(two3Texture);
                    if (angle == 50)
                        two1Sprite.setTexture(two4Texture);
                    if (angle == 60)
                        two1Sprite.setTexture(two5Texture);
                }
                window.clear();
                window.draw(phonSprite);
                window.draw(one1Sprite);
                window.draw(two1Sprite);
                window.draw(cannonSprite);
                window.draw(heart1Sprite);
                window.draw(heart2Sprite);
                window.draw(heart3Sprite);
                window.draw(tank1Sprite);
                window.draw(tank2Sprite);
                window.draw(tank3Sprite);
                window.draw(shellSprite);
                window.draw(text);
                window.draw(text2);
                window.draw(text3);
                window.draw(GameOverSprite);
                window.display();
                if (event.key.code == sf::Keyboard::Space && !isShooting && isGameOver) {
                    isShooting = true;
                    remainingShells--;
                    text.setString(std::to_string(remainingShells));
                    projectilePosition = cannonSprite.getPosition();
                    projectileVelocity.x = power * cos(angle * 3.14f / 180);
                    projectileVelocity.y = -power * sin(angle * 3.14f / 180);
                }
                if (event.key.code == sf::Keyboard::R && !isGameOver) {
                    result = true;
                }
            }
        }
        if (isShooting)
        {
            // Обновление положения снаряда с учётом физики
            projectileVelocity.y += gravity * timeStep;
            projectilePosition += projectileVelocity * timeStep;
            ballSprite.setPosition(projectilePosition); // Перемещение спрайта снаряда
            sf::Vector2f coordTank1 = sf::Vector2f(tank1Position.x + 60, tank1Position.y + 40);
            sf::Vector2f coordTank2 = sf::Vector2f(tank2Position.x + 60, tank2Position.y + 40);
            sf::Vector2f coordTank3 = sf::Vector2f(tank3Position.x + 60, tank3Position.y + 40);
            if (distance_func(projectilePosition, coordTank1) < 50) {
                if (tank1Health > 0) {
                    tank1Health--;
                    heart1Sprite.setTexture(heart1Texture);
                }
                if (tank1Health == 0) {
                    tank1Sprite.setTexture(bombtankTexture);
                    heart1Sprite.setTexture(heart0Texture);
                }
                isShooting = false;
            }
            if (distance_func(projectilePosition, coordTank2) < 50) {
                if (tank2Health > 0) {
                    tank2Health--;
                    heart2Sprite.setTexture(heart1Texture);
                }
                if (tank2Health == 0) {
                    tank2Sprite.setTexture(bombtankTexture);
                    heart2Sprite.setTexture(heart0Texture);
                }
                isShooting = false;
            }
            if (distance_func(projectilePosition, coordTank3) < 50) {
                if (tank3Health > 0) {
                    tank3Health--;
                    heart3Sprite.setTexture(heart1Texture);
                }
                if (tank3Health == 0) {
                    tank3Sprite.setTexture(bombtankTexture);
                    heart3Sprite.setTexture(heart0Texture);
                }
                isShooting = false;
            }
            if ((tank1Health > 0 || tank2Health > 0 || tank3Health > 0) && remainingShells == 0) {
                isGameOver = false;
                isEnd = true;
            }
            else if (tank1Health == 0 && tank2Health == 0 && tank3Health == 0) {
                isGameOver = false;
                isEnd = true;
                GameOverSprite.setTexture(YouWinTexture);
            }
            // Обработка попадания в бока и землю
            if (projectilePosition.x < 0 || projectilePosition.x > 1920 || projectilePosition.y > 1080) {
                isShooting = false;
            }
        }
        if (result) {
            remainingShells = 15;
            text.setString(std::to_string(remainingShells));
            tank1Health = 2;
            tank2Health = 2;
            tank3Health = 2;

            isShooting = false;
            angle = 20.0f;
            power = 80.0f;
            isGameOver = true;
            isEnd = false;
            cannonPosition = sf::Vector2f(170.0f, 760.0f);
            tank1Position = sf::Vector2f(1500.0f, 650.0f);
            tank2Position = sf::Vector2f(1200.0f, 700.0f);
            tank3Position = sf::Vector2f(950.0f, 850.0f);

            text2.setPosition(2000, 2000);
            text3.setPosition(2000, 2000);
            one1Sprite.setTexture(one1Texture);
            two1Sprite.setTexture(two1Texture);
            tank1Sprite.setTexture(tankTexture);
            tank1Sprite.setPosition(tank1Position);
            tank2Sprite.setTexture(tankTexture);
            tank2Sprite.setPosition(tank2Position);
            tank3Sprite.setTexture(tankTexture);
            tank3Sprite.setPosition(tank3Position);
            GameOverSprite.setTexture(GameOverTexture);
            GameOverSprite.setPosition(2000, 2000);
            heart1Sprite.setTexture(heart2Texture);
            heart2Sprite.setTexture(heart2Texture);
            heart3Sprite.setTexture(heart2Texture);
            heart1Sprite.setPosition(tank1Position.x + 100, tank1Position.y - 20);
            heart2Sprite.setPosition(tank2Position.x + 100, tank2Position.y - 20);
            heart3Sprite.setPosition(tank3Position.x + 100, tank3Position.y - 20);
            result = false;
        }
        if (isGameOver) {
            window.clear();
            window.draw(phonSprite);
            window.draw(one1Sprite);
            window.draw(two1Sprite);
            window.draw(cannonSprite);
            window.draw(heart1Sprite);
            window.draw(heart2Sprite);
            window.draw(heart3Sprite);
            window.draw(tank1Sprite);
            window.draw(tank2Sprite);
            window.draw(tank3Sprite);
            window.draw(ballSprite);
            window.draw(shellSprite);
            window.draw(text);
            window.draw(GameOverSprite);
            window.display();
        }
        else if (!isEnd) {
            text2.setPosition(800, 500);
            text3.setPosition(800, 550);
            window.clear();
            window.draw(phonSprite);
            window.draw(text2);
            window.draw(text3);
            window.display();
        }  
        else {
            text2.setPosition(800, 100);
            text3.setPosition(800, 150);
            window.clear();
            window.draw(phonSprite);
            window.draw(text2);
            window.draw(text3);
            GameOverSprite.setPosition(500, 300);
            window.draw(GameOverSprite);
            window.display();
        }
    }
    return 0;
}

