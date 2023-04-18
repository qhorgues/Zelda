#ifndef Main_Interface_S_HPP
#define Main_Interface_S_HPP

namespace Graphics
{
    namespace Main_Interface
    {
        class Main_Interface_S
        {
        public:
            Main_Interface_S() = default;
            
            Main_Interface_S(Main_Interface_S const&) = delete;
            Main_Interface_S& operator=(Main_Interface_S const&) = delete;

            Main_Interface_S(Main_Interface_S &&) = delete;
            Main_Interface_S& operator=(Main_Interface_S &&) = delete;

            virtual void update() = 0;

        protected:
            ~Main_Interface_S() = default;

        private:
        };
    };

}

#endif