<?hh // strict

namespace Goul\Http;

use Psr\Http\Message\UploadedFileInterface;
use Psr\Http\Message\StreamInterface;

/**
 * TODO
 * {@inheritdoc}
 */
class UploadedFile implements UploadedFileInterface
{
    /**
     * {@inheritdoc}
     */
    public function getStream(): StreamInterface
    {
        return new Stream();
    }

    /**
     * {@inheritdoc}
     */
    public function moveTo(string $targetPath): void
    {
    }
    
    /**
     * {@inheritdoc}
     */
    public function getSize(): ?int
    {
        return 0;
    }
    
    /**
     * {@inheritdoc}
     */
    public function getError(): int
    {
        return 0;
    }
    
    /**
     * {@inheritdoc}
     */
    public function getClientFilename(): ?string
    {
        return '';
    }
    
    /**
     * {@inheritdoc}
     */
    public function getClientMediaType(): ?string
    {
        return '';

    }
}
