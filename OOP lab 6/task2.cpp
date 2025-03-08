#include <iostream>
#include <vector>
using namespace std;

// Base class
class MediaFile {
protected:
    string filePath;
    double size; // in MB
public:
    MediaFile(string path, double sz) : filePath(path), size(sz) {}
    virtual void play() = 0; // Pure virtual
    virtual void stop() { cout << "Stopping media: " << filePath << endl; }
    virtual ~MediaFile() {}
};

// Intermediate class for visual media
class VisualMedia : virtual public MediaFile {
protected:
    string resolution;
public:
    VisualMedia(string path, double sz, string res) : MediaFile(path, sz), resolution(res) {}
};

// Intermediate class for audio media
class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate; // in Hz
public:
    AudioMedia(string path, double sz, int rate) : MediaFile(path, sz), sampleRate(rate) {}
};

// Derived class for Image files
class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double sz, string res) : VisualMedia(path, sz, res), MediaFile(path, sz) {}
    void play() override { cout << "Displaying image: " << filePath << " at resolution " << resolution << endl; }
};

// Derived class for Audio files
class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double sz, int rate) : AudioMedia(path, sz, rate), MediaFile(path, sz) {}
    void play() override { cout << "Playing audio: " << filePath << " with sample rate " << sampleRate << "Hz" << endl; }
};

// Derived class for Video files inheriting both VisualMedia and AudioMedia
class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double sz, string res, int rate)
        : MediaFile(path, sz), VisualMedia(path, sz, res), AudioMedia(path, sz, rate) {}
    void play() override { cout << "Playing video: " << filePath << " at " << resolution << " with " << sampleRate << "Hz audio" << endl; }
};

int main() {
    vector<MediaFile*> library;
    
    library.push_back(new ImageFile("image.png", 2.5, "1920x1080"));
    library.push_back(new AudioFile("song.mp3", 5.0, 44100));
    library.push_back(new VideoFile("movie.mp4", 700.0, "1280x720", 48000));
    
    for (MediaFile* media : library) {
        media->play();
        media->stop();
    }
    
    // Cleanup
    for (MediaFile* media : library) {
        delete media;
    }
    return 0;
}
