#ifndef COLOR_H_
#define COLOR_H_

namespace spic {

    /**
     * @brief Color represents a red-green-blue color with alpha.
     */
    class Color {
        public:
            /**
             * @brief Constructor, accepting an rgb value and an alpha (transparency).
             * @param r The red component, 0 ≤ r ≤ 1.
             * @param g The green component, 0 ≤ g ≤ 1.
             * @param b The blue component, 0 ≤ b ≤ 1.
             * @param alpha The transparency component, 0 ≤ alpha ≤ 1.
             */
            Color(double r, double g, double b, double alpha);

            /**
             * @brief One of the standard colors (read-only): white.
             * @return A reference to a statically allocated Color instance.
             */
            static const Color& white() { return _white; }
            // ... more standard colors here

        private:
            double red;
            double green;
            double blue;
            double alpha;

            static Color _white;
            // ... more standard color here
    };

}

#endif // COLOR_H_
