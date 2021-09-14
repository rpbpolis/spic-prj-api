#ifndef COLOR_H_
#define COLOR_H_

namespace spic {

    /**
     * @brief Color represents a red-green-blue color with alpha.
     */
    class Color {
        public:
            /**
             * @brief Constructor, accepting an rgb value.
             * @param red The red component, 0 ≤ r ≤ 1.
             * @param green The green component, 0 ≤ g ≤ 1.
             * @param blue The blue component, 0 ≤ b ≤ 1.
             */
            Color(const double red, const double green, const double blue);
            
            /**
             * @brief Constructor, accepting an rgb value and an alpha (transparency).
             * @param red The red component, 0 ≤ r ≤ 1.
             * @param green The green component, 0 ≤ g ≤ 1.
             * @param blue The blue component, 0 ≤ b ≤ 1.
             * @param alpha The transparency component, 0 ≤ alpha ≤ 1.
             */
            Color(const double red, const double green, const double blue, const double alpha);

            /**
             * @brief One of the standard colors (read-only): white.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& white()   { return _white; }

            /**
             * @brief One of the standard colors (read-only): red.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& red()     { return _red; }

            /**
             * @brief One of the standard colors (read-only): green.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& green()   { return _green; }

            /**
             * @brief One of the standard colors (read-only): blue.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& blue()    { return _blue; }

            /**
             * @brief One of the standard colors (read-only): cyan.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& cyan()    { return _cyan; }

            /**
             * @brief One of the standard colors (read-only): magenta.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& magenta() { return _magenta; }

            /**
             * @brief One of the standard colors (read-only): yellow.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& yellow()  { return _yellow; }

            /**
             * @brief One of the standard colors (read-only): black.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& black()   { return _black; }
            // ... more standard colors here

        private:
            double r;
            double g;
            double b;
            double a;

            static Color _white;
            static Color _red;
            static Color _green;
            static Color _blue;
            static Color _cyan;
            static Color _magenta;
            static Color _yellow;
            static Color _black;
            // ... more standard color here
    };

}

#endif // COLOR_H_
