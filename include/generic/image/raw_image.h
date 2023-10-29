#pragma once
#include "image.h"

namespace sc
{
    class RawImage : public Image
    {
    public:
        RawImage(const RawImage&) = delete;

        RawImage(uint8_t* data, uint16_t width, uint16_t height, Image::BasePixelType type, Image::ColorSpace space = Image::ColorSpace::Linear) : m_data(data), m_type(type), m_space(space);

        RawImage(uint16_t width, uint16_t height, Image::BasePixelType type) : m_type(type);

        ~RawImage();

    public:
        virtual size_t data_length();
        virtual uint8_t* data();

        virtual BasePixelType base_type() const;

        virtual ColorSpace colorspace() const;

        virtual bool is_compressed() const
        {
            return false;
        };

    public:
        Image* resize(uint16_t new_width, uint16_t new_height);

        void write(Stream& buffer);

    private:
        Image::BasePixelType m_type;
        Image::ColorSpace m_space;

        uint8_t* m_data;
        uint8_t* m_allocated_data;
    };
}