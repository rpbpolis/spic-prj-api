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
            Color(double red, double green, double blue);
            
            /**
             * @brief Constructor, accepting an rgb value and an alpha (transparency).
             * @param red The red component, 0 ≤ r ≤ 1.
             * @param green The green component, 0 ≤ g ≤ 1.
             * @param blue The blue component, 0 ≤ b ≤ 1.
             * @param alpha The transparency component, 0 ≤ alpha ≤ 1.
             */
            Color(double red, double green, double blue, double alpha);

            /**
             * @brief One of the standard colors (read-only): white.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& white() { return _white; }

            /**
             * @brief One of the standard colors (read-only): red.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& red() { return _red; }

            /**
             * @brief One of the standard colors (read-only): green.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& green() { return _green; }

            /**
             * @brief One of the standard colors (read-only): blue.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& blue() { return _blue; }

            /**
             * @brief One of the standard colors (read-only): cyan.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& cyan() { return _cyan; }

            /**
             * @brief One of the standard colors (read-only): magenta.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& magenta() { return _magenta; }

            /**
             * @brief One of the standard colors (read-only): yellow.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& yellow() { return _yellow; }

            /**
             * @brief One of the standard colors (read-only): black.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& black() { return _black; }

            /**
             * @brief One of the standard colors (read-only): purple.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& purple() { return _purple; }

            /**
             * @brief One of the standard colors (read-only): lime.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& lime() { return _lime; }

            /**
             * @brief One of the standard colors (read-only): orange.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& orange() { return _orange; }

            /**
             * @brief One of the standard colors (read-only): transparent.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& transparent() { return _transparent; }
            // ... more standard colors here

            /**
             * @brief Set the RGB values of the color
             * @param r The red part of the color
             * @param g The green part of the color
             * @param b The blue part of the color
             */
            void Color(double r, double g, double b);

            /**
             * @brief Set the RGBA values of the color
             * @param r The red part of the color
             * @param g The green part of the color
             * @param b The blue part of the color
             * @param a The alpha part of the color
             */
            void Color(double r, double g, double b, double a);
            
            /**
             * @brief The red part of the color
             * @return A reference to the statically red part of the color.
             */
            double& R() const { return r; }

            /**
             * @brief The green part of the color
             * @return A reference to the statically green part of the color.
             */
            double& G() const { return g; }
            
            /**
             * @brief The blue part of the color
             * @return A reference to the statically blue part of the color.
             */
            double& B() const { return b; }

            /**
             * @brief The alpha part of the color
             * @return A reference to the statically alpha part of the color.
             */
            double& A() const { return a; }

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
            static Color _purple;
            static Color _lime;
            static Color _orange;
            static Color _transparent;
            // ... more standard color here
    };

}

#endif // COLOR_H_
