/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** ResourceManager
*/

#include <filesystem>
#include "ResourceManager.hpp"
#include "parsing.hpp"

    ResourceManager::ResourceManager()
    {
        loadAssets();
    }

    void ResourceManager::loadAssets()
    {

        loadTexture("menu_bg", "asset/texture/menu_bg.png");
        loadTexture("cursor", "asset/texture/cursor.png");

        loadFont("debugFont", "asset/font/debug_font.ttf");
        loadFont("title_font", "asset/font/Shikamaru.ttf");
    }

    ResourceManager &ResourceManager::getInstance()
    {
        static ResourceManager instance;
        return instance;
    }

    void ResourceManager::loadTexture(const std::string &name, const std::string &filename)
    {
        // Create a new texture and load it from the specified file.
        sf::Texture texture;
        texture.loadFromFile(filename);

        std::cout << "Loaded texture as \"" << name << "\" from "
                  << "\"" + filename + "\"" << std::endl;

        // Insert the texture into the map using the name as the key.
        m_textures[name] = texture;
        m_images[name] = texture.copyToImage();
    }

    sf::Texture &ResourceManager::getTexture(const std::string &name)
    {
        return m_textures.at(name);
    }

    sf::Image &ResourceManager::getTextureImage(const std::string &name)
    {
        return m_images.at(name);
    }

    void ResourceManager::loadTexturesFromFolder(const std::string &directory)
    {
        for (const auto &entry : std::filesystem::directory_iterator(directory))
            loadTexture(removeExtension(entry.path().filename()), entry.path().string());
    }

    void ResourceManager::loadFont(const std::string &name,
                                   const std::string &filePath)
    {
        auto &font = m_fonts[name];
        if (!font.loadFromFile(filePath))
            throw std::runtime_error("Failed to load font: " + filePath);
        m_fonts[name] = font;
        std::cout << "Loaded font as \"" << name << "\" from "
                  << "\"" + filePath + "\"" << std::endl;
    }

    sf::Font &ResourceManager::getFont(const std::string &fontName)
    {
        if (m_fonts.count(fontName) == 0)
            m_fonts[fontName].loadFromFile(fontName);
        return m_fonts.at(fontName);
    }

    void ResourceManager::loadSoundBuffer(const std::string &name,
                                          const std::string &fileName)
    {
        sf::SoundBuffer soundBuffer;
        if (!soundBuffer.loadFromFile(fileName))
            throw std::runtime_error("Failed to load sound buffer: " + fileName);
        m_soundBuffers[name] = soundBuffer;
        std::cout << "Loaded font as \"" << name << "\" from "
                  << "\"" + fileName + "\"" << std::endl;
    }

    sf::SoundBuffer &ResourceManager::getSoundBuffer(const std::string &name)
    {
        auto it = m_soundBuffers.find(name);
        if (it == m_soundBuffers.end())
            throw std::runtime_error("Sound buffer not found: " + name);
        return m_soundBuffers.at(name);
    }

    void ResourceManager::loadMusic(const std::string &name, const std::string &filePath)
    {
        std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();

        if (!music->openFromFile(filePath))
            throw std::runtime_error("Failed to load music: " + filePath);
        m_musics[name] = std::move(music);
        std::cout << "Loaded music as \"" << name << "\" from "
                  << "\"" + filePath + "\"" << std::endl;
    }

    sf::Music &ResourceManager::getMusic(const std::string &name)
    {
        if (m_musics.count(name) == 0)
            m_musics[name] = std::make_unique<sf::Music>();
        return *m_musics.at(name);
    }