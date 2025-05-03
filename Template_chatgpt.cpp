#include <iostream>
// Abstract class (template)
class DataProcessor{
    public:
        // Template method
        void processData() {
            readData();
            processDataStep();
            saveData();
        }

        virtual ~DataProcessor() {}

    protected:
        virtual void readData(){
            std::cout << "Reading data from source..." << std::endl;
        }
        virtual void processDataStep() = 0;
        virtual void saveData() {
            std::cout << "Saving processed data..." << std::endl;
        }

};
// Concrete class
class CSVDataProcessor : public DataProcessor {
    protected:
        void processDataStep() override {
            std::cout << "Processing CSV data..." << std::endl;
        }
};
// Concrete class
class JSONDataProcessor : public DataProcessor {
    protected:
        void processDataStep() override {
            std::cout << "Processing JSON data..." << std::endl;
        }
};
// Usage
int main() {
    DataProcessor* csvProcessor = new CSVDataProcessor();
    csvProcessor->processData();

    DataProcessor* jsonProcessor = new JSONDataProcessor();
    jsonProcessor->processData();

    delete csvProcessor;
    delete jsonProcessor;

    return 0;
}